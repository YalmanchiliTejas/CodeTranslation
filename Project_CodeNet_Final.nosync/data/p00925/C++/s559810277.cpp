#include <cctype>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long expression1(vector<string>);
long long expression2(vector<string>);

string to_string(char c)
{
	string S; S = c;

	return S;
}

vector<string> to_expression(string S)
{
	vector<string> v; int sum = 0;

	for (int i = 0; i < S.size(); i++)
	{
		if (isdigit(S[i]))
		{
			sum *= 10; sum += (S[i] - 48);
		}
		else
		{
			v.push_back(to_string(sum)); sum = 0; v.push_back(to_string(S[i]));
		}
	}

	v.push_back(to_string(sum));

	return v;
}

long long expression1(vector<string> v)
{
	vector<string> v2;

	long long sum = stoi(v[0]);

	for (int i = 1; i < v.size(); i += 2)
	{
		if (v[i] == "+")
		{
			v2.push_back(to_string(sum)); v2.push_back("+"); sum = stoll(v[i + 1]);
		}
		else
		{
			sum *= stoll(v[i + 1]);
		}
	}

	v2.push_back(to_string(sum));

	return expression2(v2);
}

long long expression2(vector<string> v)
{
	long long sum = stoi(v[0]);

	for (int i = 1; i < v.size(); i += 2)
	{
		if (v[i] == "+")
		{
			sum += stoll(v[i + 1]);
		}
		else
		{
			sum *= stoll(v[i + 1]);
		}
	}

	return sum;
}

int main()
{
	string S; int N;

	cin >> S >> N;

	long long res1 = expression1(to_expression(S));
	long long res2 = expression2(to_expression(S));

	int ret = (res1 == N ? 2 : 0) + (res2 == N ? 1 : 0);

	switch (ret)
	{
		case 3: cout << "U" << endl; break;
		case 2: cout << "M" << endl; break;
		case 1: cout << "L" << endl; break;
		case 0: cout << "I" << endl; break;
	}

	return 0;
}