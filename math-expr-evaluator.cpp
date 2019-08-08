#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

double add_sub(vector<double> &nums,vector<char> &ops)
{
  // evaluate + and - opeartors
  double sum = nums[0];
  double num;
  for(int i=0;i<ops.size();i++)
  {
    num = nums[i+1];
    if(ops[i]=='+') sum += num;
    else if(ops[i]=='-') sum -= num;
    else throw("Fatal Error!!");
  }

  return sum;
}

double mul_div(vector<double> &v,vector<char> &ops)
{
  // only evaluate * and / operators
  double num1,num2;
  for(int i=0;i<ops.size();i++)
  {
    if(ops[i]=='*' || ops[i]=='/')
    {
      num1 = v[i]; // get the previous element
      num2 = v[i+1]; // get the next element
      if(ops[i]=='*') v[i+1] = num1*num2; // evaluate expression
      else v[i+1] = num1/num2;
      if(i>0) ops[i] = ops[i-1]; // set the new opeartor after evaluation
      else ops[i] = '+';
      v[i] = 0;
    }
  }
  return add_sub(v,ops);
}

double eval(stringstream &ss)
{
	vector<double> v; // v holds all numbers
  vector<char> ops; // ops holds all the operators
  double num;
  char next;
  bool unary = true;
  // get the next element in stream
  while(ss>>next)
  {
    if(next==' ') continue; // if it is space then skip and check next element
    else if(next=='(') // if it a bracket opening then evaluate it first
    {
      unary = false;
      v.push_back(eval(ss));
    }
    else if(next==')') // return evaluated bracket when it closes
    {
      return mul_div(v,ops);
    }
    else if((next=='+'||next=='-') && unary) // check for unary operator
    {
      ss >> num;
      if(next=='+') v.push_back(num);
      else v.push_back(-num);
      unary = false;
    }
    else if(next=='+'||next=='-'||next=='*'||next=='/') // checks for opeartors
    {
      unary = true;
      ops.push_back(next);
    }
    else // extract number from stream
    {
      ss.putback(next);
      ss >> num;
      v.push_back(num);
      unary = false;
    }
  }

	return mul_div(v,ops);
}


// driver code
int main()
{
	string s;
	getline(cin,s);
	stringstream ss(s);
	double num = eval(ss);
	cout << "Result is: " << num << endl;

	return 0;
}
