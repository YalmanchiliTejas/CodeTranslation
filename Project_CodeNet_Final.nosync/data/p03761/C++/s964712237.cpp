#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;

template <class T, class U>
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
		if (min_len > s[i].size())
		{
			min_len = s[i].size();
			m = i;
		}
	}
	string ans;
	rep(i, s[m].size())
	{
		int cnt = 0;
		rep(j, n)
		{
			if (contain(s[j], s[m][i]))
			{
				cnt++;
				if (j != m)
					s[j].erase(s[j].find(s[m][i]), 1);
			}
		}
		if (cnt == n)
			ans.push_back(s[m][i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
