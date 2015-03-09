// calc.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Calculator.h"

using namespace std;

int main(int argc, char* argv[]) {

    string expression;
    while (true)
    {
        Calculator calc;
        cout << "> ";
        getline(cin, expression);

        calc.getExpression(expression);
        if("quit" == expression)
        {
            break;
        }
        else if (!calc.isGoodExpression())
        {
            cout << "Error: Wrong expression" << endl;
        }
        else if (!calc.isMathOperator())
        {
            cout << "Error: Wrong sign" << endl;
        }
        else
        {
            calc.displayReault();
        }
    }
    return 0;
}
