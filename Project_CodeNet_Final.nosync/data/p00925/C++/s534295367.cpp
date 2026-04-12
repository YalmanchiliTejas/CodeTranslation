#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

void solve()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int BobsAns;
	cin >> s >> BobsAns;
	int ansL = s[0] - '0';
	for (int i = 2; i < s.size(); i += 2)
	{
		if (s[i - 1] == '+')
		{
			ansL += s[i] - '0';
		}
		else
		{
			ansL *= s[i] - '0';
		}
	}
	int ansM = 0;
	stack<int> num;
	for (int i = 0; i < s.size(); ++i)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			num.push(s[i] - '0');
		}
		else if (s[i] == '*')
		{
			int a = num.top();
			num.pop();
			a *= s[i + 1] - '0';
			num.push(a);
			++i;
		}
	}
	while (!num.empty())
	{
		ansM += num.top();
		num.pop();
	}
	if (ansL == BobsAns && ansM == BobsAns)
	{
		cout << "U" << endl;
	}
	else if (ansM == BobsAns)
	{
		cout << "M" << endl;
	}
	else if (ansL == BobsAns)
	{
		cout << "L" << endl;
	}
	else
	{
		cout << "I" << endl;
	}
}

int main()
{
	solve();
	return(0);
}