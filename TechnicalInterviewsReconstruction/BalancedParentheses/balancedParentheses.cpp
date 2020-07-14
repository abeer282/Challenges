#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool balanced(string exp) {
	vector<char> par;
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')

			par.push_back(exp[i]);
		else if (exp[i] == ')') 
			if (par.size() > 0 && par[par.size() - 1] == '(')
				par.pop_back();
			else
				return false;
		else  if (exp[i] == ']') 
			if (par.size() > 0 &&  par[par.size() - 1] == '[')
				par.pop_back();
			else
				return false;
		else  if (exp[i] == '}') 
			if (par.size() > 0 &&  par[par.size() - 1] == '{')
				par.pop_back();
			else
				return false;
	}
	if(par.size()==0)
		return true;
	return false;
}


int main()
{
	string expression;
	cin >> expression;
	if (balanced(expression))
		cout << "Balanced Parentheses!";
	else
		cout << "Unbalanced Parentheses!";
	cout << '\n';

	return 0;
}