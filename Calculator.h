#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Calculator
{
public:
    Calculator(void);
    ~Calculator(void);
    int getExpression(std::string a_expression);
    void displayReault() const;
    bool isGoodExpression() const;
    bool isMathOperator() const;

private:
    double operation();
    void tokenization(std::string a_expressionToTokenize);
    void toDoubleOnStack(std::string& a_tokenstring,int a_currentToken);
    bool isDigit(std::string& a_tokenstring);
    void clearStack();

    bool m_isGoodExpression;
    bool m_hasGoodSign;
    double m_operationResault;
    std::stack <double>  m_stackNumber;
    std::vector <std::string> m_tokens;
    std::string m_mathSign;

};


