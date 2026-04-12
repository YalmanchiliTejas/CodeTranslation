#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define rep(i, s, e) for (auto i = s; i < e; i++)
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';

void solve()
{
	int n;
	cin >> n;
	string gen = "abcdefghijklmnopqrstuvwxyz", az = "";
	for (char i : gen)
	{
		rep(x, 0, 50)
		{
			az += i;
		}
	}
	multiset<char> ss(all(az));
	rep(i, 0, n)
	{
		string s;
		cin >> s;
		multiset<char> in(all(s));
		string t;
		set_intersection(all(ss), all(in), back_inserter(t));
		ss.clear();
		ss = multiset<char>(all(t));
	}
	cout << string(all(ss));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "\n\n~" << 500 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}