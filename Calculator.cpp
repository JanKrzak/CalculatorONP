#include "Calculator.h"
#include <sstream>

using namespace std;

Calculator::Calculator(void):
    m_isGoodExpression(true),
    m_hasGoodSign(true),
    m_operationResault(0)
{
}

Calculator::~Calculator(void)
{
}

bool Calculator::isGoodExpression() const
{
    return m_isGoodExpression;
}
bool Calculator::isMathOperator() const
{
    return m_hasGoodSign;
}
bool Calculator::isDigit(string& a_tokenString)
{
if ((a_tokenString >= "0") && (a_tokenString < "9"))
{
    return true;
}
return false;
}

void Calculator::clearStack()
{
    while (!m_stackNumber.empty())
    {
        m_stackNumber.pop();
    }
}

void Calculator::toDoubleOnStack(string& a_tokenString, int a_currentToken)
{
    double number;
    stringstream data[m_tokens.size()];
    data[a_currentToken] << a_tokenString;
    data[a_currentToken] >> number;
    //number = stod(tokenString);
    m_stackNumber.push(number);
}
void Calculator::tokenization(string a_expressionToTokenize)
{
    string tokenTemp;
    istringstream iss(a_expressionToTokenize);
    while (!iss.eof ())
    {
        iss >> tokenTemp;
        m_tokens.push_back(tokenTemp);
    }
}

int Calculator::getExpression(string a_expression)
{

    int numberOfDigits = 0;
    int numberofSign = 0;
    string tokenString;

    tokenization(a_expression);

    for (unsigned i = 0; i < m_tokens.size(); i++)
    {
        tokenString = m_tokens[i];

        if (isDigit(tokenString))
        {
            toDoubleOnStack(tokenString, i);
            numberOfDigits++;
        }
        else
        {
            numberofSign++;
            m_mathSign = m_tokens[i];
            if (numberofSign >= numberOfDigits)
            {
                m_isGoodExpression = false;
                return 0;
            }
            m_operationResault = operation();
        }
        if (!isMathOperator())
        {
            return 0;
        }
    }
    if (numberofSign < numberOfDigits - 1 || numberOfDigits < 2)
    {
        m_isGoodExpression = false;
        return 0;
    }
    clearStack();
    return 0;
}

double Calculator::operation()
{
    double value = 0, resault = 0;
    if(m_mathSign == "+")
    {
        value = m_stackNumber.top();
        m_stackNumber.pop();
        resault = value + m_stackNumber.top();
        m_stackNumber.pop();
    }
    else if(m_mathSign == "-")
    {
        value = m_stackNumber.top();
        m_stackNumber.pop();
        resault = m_stackNumber.top() - value;
        m_stackNumber.pop();
    }
    else if(m_mathSign == "*")
    {
        value = m_stackNumber.top();
        m_stackNumber.pop();
        resault = value * m_stackNumber.top();
        m_stackNumber.pop();
    }
    else if(m_mathSign == "/")
    {
        value = m_stackNumber.top();
        if(value == 0.0)
        {
           cout<<"\nDivision by 0"<<endl;
           m_isGoodExpression = false;
        }
        m_stackNumber.pop();
        resault = m_stackNumber.top() / value;
        m_stackNumber.pop();
    }
    else
    {
        m_hasGoodSign = false;
    }
    m_stackNumber.push(resault);
    return resault;
}

void Calculator::displayReault() const
{
    cout<<"Resault: "<<m_operationResault<<endl;
}
