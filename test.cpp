#include<iostream>
#include "math-expr-evaluator.h"
#include<string>

using namespace std;

// driver code

int main()
{
	string s;
	cout << "Enter expression to eval: ";
	getline(cin,s);
	stringstream ss(s);
	double result = eval(ss);
	cout << "Expression is: " << ss.str() << endl;
	cout <<  "Result is: " << result << endl;

	return 0;
}
