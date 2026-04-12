#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

using namespace std;

int main(int argc, char** argv) 
{
#ifdef HOME
	if(IsDebuggerPresent())
	{
		freopen("../in.txt", "rb", stdin);
		freopen("../out.txt", "wb", stdout);
	}
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	int N;
	cin >> N;
	vector<int64_t> a(N);
	for (auto& ai : a)
		cin >> ai;
	vector<int64_t> dp = a, dp2(N);
	if (N % 2 == 0)
	{
		for (auto& di : dp)
			di = -di;
	}
	fore(i, 2, N)
	{
		fill(all(dp2), 0);
		if ((N - i) & 1)
		{
			//minimize
			forn(j, N - i + 1)
			{
				dp2[j] = min(-a[j] + dp[j + 1], dp[j] - a[j + i - 1]);
			}
		}
		else
		{
			//maximize
			forn(j, N - i + 1)
			{
				dp2[j] = max(a[j] + dp[j + 1], dp[j] + a[j + i - 1]);
			}
		}
		dp.swap(dp2);
	}
	cout << dp[0] << endl;
	return 0;
}
