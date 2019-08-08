#ifndef MATH_EXPR_EVALUATOR
#define MATH_EXPR_EVALUATOR

#include<sstream>
#include<vector>

double add_sub(std::vector<double> &nums,std::vector<char> &ops);
double mul_div(std::vector<double> &v,std::vector<char> &ops);
double eval(std::stringstream &ss);

#endif
