/*******************************************************************************************
 *   X X X X  X X X X X  X     X  X X X X X  X X X X    X X X X  X X X X  X X X      X X X
 * X              X      X X   X      X      X        X          X        X     X  X
 * X   X X X      X      X  X  X      X      X X X X  X   X X X  X X X X  X X X      X X
 * X       X      X      X   X X      X      X        X       X  X        X   X          X
 *   X X X    X X X X X  X     X      X      X X X X    X X X    X X X X  X     X  X X X
 *******************************************************************************************
 *
 * This file is part of GIntegers by GaryNLOL.
 * Special thanks to my family and µ's.
 *
 * MIT License
 * Copyright (c) 2020 GaryNLOL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>

static_assert('0' + 9 == '9',"The current encoding is not supported by GIntegers.");

namespace GIntegers
{
    class GInt
    {
    private:
        std::string val;
        bool isNegative;
        static bool isValidInput(const std::string& str)
        {
            if(str.size() == 0 || str == "-")
                return false;
            for(std::string::size_type i = (str[0] == '-'); i < str.size(); i++)
                if(!std::isdigit(str[i]))
                    return false;
            return true;
        }
        void deleteTrailingZeroes()
        {
            for(unsigned int i = 0; i < this->val.size(); i++)
            {
                if(this->val[i] != '0' || i == this->val.size()-1)
                {
                    this->val.erase(0,i);
                    break;
                }
            }
        }
    public:
        GInt()
        {
            this->isNegative = false;
            this->val = "0";
        }
        GInt(const std::string& newVal)
        {
            if(!isValidInput(newVal))
                throw std::invalid_argument("GInt::GInt(" + newVal + ")");
            this->isNegative = (newVal[0] == '-');
            this->val = newVal.substr(isNegative,newVal.size()-isNegative);
            this->deleteTrailingZeroes();
        }
        template<typename int_type, typename = typename std::enable_if<std::is_integral<int_type>::value>::type>
        GInt(const int_type newVal)
        {
            *this = GInt(std::to_string(newVal));
        }
        std::string to_string() const
        {
            return this->isNegative ? ("-" + this->val):(this->val);
        }
        friend std::ostream& operator<<(std::ostream& stream, const GInt& num)
        {
            stream << num.to_string();
            return stream;
        }
        friend std::istream& operator>>(std::istream& stream, GInt& num)
        {
            std::string checkStr;
            stream >> checkStr;
            num = GInt(checkStr);
            return stream;
        }
        bool operator==(const GInt& num2) const
        {
            return (this->isNegative == num2.isNegative) && (this->val == num2.val);
        }
        bool operator!=(const GInt& num2) const
        {
            return !(*this == num2);
        }
        bool operator>(const GInt& num2) const
        {
            if(this->isNegative && !num2.isNegative)
            {
                return false;
            }
            if(!this->isNegative && num2.isNegative)
            {
                return true;
            }
            if(!this->isNegative && !num2.isNegative)
            {
                if(this->val.size() > num2.val.size())
                {
                    return true;
                }
                if(this->val.size() < num2.val.size())
                {
                    return false;
                }
                if(this->val.size() == num2.val.size())
                {
                    for(std::string::size_type i = 0; i < this->val.size(); i++)
                    {
                        if(this->val[i] > num2.val[i])
                            return true;
                        if(this->val[i] < num2.val[i])
                            return false;
                    }
                    return false;
                }
            }
            if(this->isNegative && num2.isNegative)
            {
                if(this->val.size() > num2.val.size())
                {
                    return false;
                }
                if(this->val.size() < num2.val.size())
                {
                    return true;
                }
                if(this->val.size() == num2.val.size())
                {
                    for(std::string::size_type i = 0; i < this->val.size(); i++)
                    {
                        if(this->val[i] > num2.val[i])
                            return false;
                        if(this->val[i] < num2.val[i])
                            return true;
                    }
                    return false;
                }
            }
            throw std::invalid_argument("GInt::operator>(Not possible case)");
        }
        bool operator<=(const GInt& num2) const
        {
            return *this == num2 || *this < num2;
        }
        bool operator>=(const GInt& num2) const
        {
            return *this == num2 || *this > num2;
        }
        bool operator<(const GInt& num2) const
        {
            return !(*this == num2 || *this > num2);
        }
        GInt operator+(const GInt& num2) const
        {
            if(this->isNegative == num2.isNegative)
            {
                std::string answer;
                int carry = 0;
                for(int i = this->val.size()-1, j = num2.val.size()-1; i >= 0 || j >= 0 || carry != 0; i--, j--)
                {
                    int operand1 = (i >= 0) ? (this->val[i] - '0'):(0);
                    int operand2 = (j >= 0) ? (num2.val[j] - '0'):(0);
                    int result = operand1 + operand2 + carry;
                    if(result >= 10)
                    {
                        carry = 1;
                        result -= 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    answer += char(result + '0');
                }
                answer = std::string(answer.rbegin(),answer.rend());
                return GInt(this->isNegative ? ("-" + answer):(answer));
            }
            else
            {
                const GInt& positive = this->isNegative ? num2.val:this->val;
                const GInt& negative = this->isNegative ? this->val:num2.val;
                if(positive == negative)
                    return GInt(0);
                std::string answer;
                int carry = 0;
                bool resultIsNegative = negative > positive;
                for(int i = positive.val.size()-1, j = negative.val.size()-1; i >= 0 || j >= 0 || carry != 0; i--, j--)
                {
                    int operand1 = (i >= 0) ? (positive.val[i] - '0'):0;
                    int operand2 = (j >= 0) ? (negative.val[j] - '0'):0;
                    int result;
                    if(resultIsNegative)
                        result = operand2 - (operand1 + carry);
                    else
                        result = operand1 - (operand2 + carry);
                    if(0 > result)
                    {
                        carry = 1;
                        result += 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    answer += char(result + '0');
                }
                answer = (resultIsNegative ? "-":"") + std::string(answer.rbegin(), answer.rend());
                return GInt(answer);
            }
        }
        GInt operator-(const GInt& num2) const
        {
            GInt invertedSignNum2(num2);
            invertedSignNum2.isNegative = !invertedSignNum2.isNegative;
            return *this + invertedSignNum2;
        }
        GInt operator+=(const GInt& num2)
        {
            *this = *this + num2;
            return *this;
        }
        GInt operator-=(const GInt& num2)
        {
            *this = *this - num2;
            return *this;
        }
        GInt operator++(int)
        {
            GInt ret = *this;
            *this = *this + GInt(1);
            return ret;
        }
        GInt operator++()
        {
            *this = *this + 1;
            return *this;
        }
        GInt operator--(int)
        {
            GInt ret = *this;
            *this = *this - GInt(1);
            return ret;
        }
        GInt operator--()
        {
            *this = *this - GInt(1);
            return *this;
        }
        GInt operator*(const GInt& num2) const
        {
            if(this->val == "0" || num2.val == "0")
                return GInt(0);
            std::vector<GInt> unitaryResults;
            for(int i = this->val.size()-1; i >= 0; i--)
            {
                std::string unitaryAnswer;
                int carry = 0;
                int operand1 = this->val[i] - '0';
                for(int j = num2.val.size()-1; j >= 0 || carry != 0; j--)
                {
                    int operand2 = (j >= 0) ? (num2.val[j]-'0'):(0);
                    int result = operand1 * operand2 + carry;
                    carry = result/10;
                    result %= 10;
                    unitaryAnswer += char(result + 48);
                }
                unitaryAnswer = std::string(unitaryAnswer.rbegin(),unitaryAnswer.rend()) + std::string(unitaryResults.size(),'0');
                unitaryResults.push_back(GInt(unitaryAnswer));
            }
            GInt answer;
            for(unsigned int i = 0; i < unitaryResults.size(); i++)
                answer += unitaryResults[i];
            answer.isNegative = (this->isNegative != num2.isNegative);
            return answer;
        }
        GInt operator*=(const GInt& num2)
        {
            *this = *this * num2;
            return *this;
        }
        GInt operator/(const GInt& num2) const
        {
            const GInt dividend = this->abs();
            const GInt divisor = num2.abs();
            GInt remainder;
            remainder.val = "";
            std::string cocient;
            unsigned int currentIndex = 0;
            while(currentIndex < dividend.val.size())
            {
                if(currentIndex < dividend.val.size())
                {
                    remainder.val += dividend.val[currentIndex];
                    currentIndex++;
                }
                if(divisor > remainder)
                {
                    cocient += "0";
                }
                else
                {
                    unsigned int counter = 0;
                    while(remainder >= divisor)
                    {
                        remainder -= divisor;
                        counter++;
                    }
                    cocient += char(counter + '0');
                }
            }
            cocient = (this->isNegative == num2.isNegative ? "":"-") + cocient;
            return GInt(cocient);
        }
        GInt operator/=(const GInt& num2)
        {
            *this = *this / num2;
            return *this;
        }
        GInt operator%(const GInt& num2) const
        {
            const GInt dividend = this->abs();
            const GInt divisor = num2.abs();
            GInt remainder;
            remainder.val = "";
            std::string cocient;
            unsigned int currentIndex = 0;
            while(currentIndex < dividend.val.size())
            {
                if(currentIndex < dividend.val.size())
                {
                    remainder.val += dividend.val[currentIndex];
                    currentIndex++;
                }
                if(remainder >= divisor)
                {
                    unsigned int counter = 0;
                    while(remainder >= divisor)
                    {
                        remainder -= divisor;
                        counter++;
                    }
                }
            }
            return remainder;
        }
        GInt operator%=(const GInt& num2)
        {
            *this = *this % num2;
            return *this;
        }
        GInt factorial() const
        {
            if(this->isNegative)
                throw std::invalid_argument("GInt::factorial(" + this->val + ")");
            GInt result = 1;
            for(GInt i = this->val; i > 0; i--)
            {
                result *= i;
            }
            return result;
        }
        GInt abs() const
        {
            if(!this->isNegative)
                return *this;
            return GInt(this->val);
        }
    };
}
