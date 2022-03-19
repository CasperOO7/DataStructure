#include<iostream>
using namespace std;
#include<stack>
bool is_pair(char open,char close) {
	if (open == '(' && close == ')')
		return true;
	if (open == '[' && close == ']')
		return true;
	if (open == '{' && close == '}')
		return true;
	return false;
}
bool is_balanced(string exp) {
	stack<char>s;
	int length = exp.length();
	for (int i = 0; i < length; i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (s.empty() || !is_pair(s.top(),exp[i]))
				return false;
			else
				s.pop();
			
		}

	}
	return s.empty();
}
int main()
{
	string expression;
	cout << "Enter Expression: ";
	cin >> expression;
	if (is_balanced(expression))
		cout << "Balanced UwU";
	else
		cout << "Not Balanced :(";







}


