#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);                      \
	cin.exceptions(cin.failbit);
#define int long long int //Comment when Unnecessary
#define ll long long
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define pii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define endl "\n" // Remove on Interactive

const int N = 300009;
const int mod = 1000000007;

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	int n, m;
	string s;
	cin >> s;
	int a = 0, b = 0;
	rep(i, 0, 3)
	{
		if (s[i] == 'A')
			a++;
		else
			b++;
	}
	if (a > 0 && b > 0)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}
