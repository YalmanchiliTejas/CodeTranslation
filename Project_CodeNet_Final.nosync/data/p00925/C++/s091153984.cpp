#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> split(string expression,char delimita)
{
	vector<string> ret;
	int startIndex = 0;
	int length = 1;
	int size = expression.size();
	while ((startIndex = expression.find(delimita)) != string::npos)
	{
		string sub = expression.substr(0,startIndex);
		string next = expression.substr(startIndex + 1);
		expression = next;
		ret.push_back(sub);
	}
	if (expression.size() > 0)ret.push_back(expression);
	return ret;
}
int multi(string exp)
{
	int ret = 1;
	for (int i = 0; i < exp.size(); i+=2)
	{
		ret *= (exp[i] - '0');
	}
	return ret;
}
bool isM(int n,string s)
{
	vector<string> exps = split(s, '+');
	int ret = 0;
	for (int i = 0; i < exps.size(); i++)
	{
		ret += multi(exps[i]);
	}
	return n == ret;
}

bool isL(int n,string s)
{
	if (s.length() == 1 && s[0] - '0' == n)return true;
	int sum = -1;
	for (int i = 1; i < s.length(); i += 2)
	{
		if (i == 1)
		{
			if (s[i] == '+')
			{
				sum = s[i - 1] - '0' + (s[i + 1] - '0');
			}
			else
			{
				sum = (s[i - 1] - '0') * (s[i + 1] - '0');
			}
		}
		else
		{
			if (s[i] == '+')
			{
				sum += (s[i + 1] - '0');
			}
			else
			{
				sum *= (s[i + 1] - '0');
			}
		}
	}

	if (sum == n)return true;
	else return false;
}

int main()
{
	string exp;
	int n;
	cin >> exp;
	cin >> n;
	bool M = isM(n, exp);
	bool L = isL(n, exp);
	if (M && L)
	{
		cout << "U" << endl;
	}
	else if (M)
	{
		cout << "M" << endl;
	}
	else if (L)
	{
		cout << "L" << endl;
	}
	else
	{
		cout << "I" << endl;
	}
	return 0;
}