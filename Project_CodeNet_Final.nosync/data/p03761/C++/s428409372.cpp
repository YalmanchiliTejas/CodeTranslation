#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

template<class T, class U>
bool contain(const std::basic_string<T>& s, const U& v)
{
	return s.find(v) != std::basic_string<T>::npos;
}

int  main()
{
	int n; cin >> n;
	vector <string> s(n);
	int min_len = INT_MAX;
	int m = 0;
	rep(i, n)
	{
		cin >> s[i];
		if (s[i].size() < min_len)
		{
			min_len = s[i].size();
			m = i;
		}
	}
	priority_queue <char, vector<char>, greater<char>> pq;
	rep(i, s[m].size())
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (contain(s[j], s[m][i]))
			{
				cnt++;
				int e = 0;
				if (j != m)
				{
					rep(k, s[j].size())
					{
						if(s[j][k] == s[m][i])
						{
							e = k; break;
						}
					}
					s[j].erase(e, 1);
				}
			}
		}
		if (cnt == n)
		{
			pq.push(s[m][i]);
		}
	}
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
	return 0;
}