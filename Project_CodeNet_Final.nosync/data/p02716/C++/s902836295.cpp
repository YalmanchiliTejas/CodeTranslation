#include <bits/stdc++.h>
using namespace std;

#define int             long long int
#define ld              long double
#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"

#define vi              vector <int>
#define pii             pair <int, int>
#define vpii            vector <pii>
#define mii             map <int, int>
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>

#define loop(i,s,e)     for(int i=s;i<e;i++)
#define rloop(i,e,s)    for(int i=e;i>=s;i--)
#define mset(a,f)       memset(a,f,sizeof(a))

#define M               1000000007
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()

#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define Print(a,x,y)    for (int i=x; i<y; i++) cout<< a[i]<< " "; cout << endl


inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;

		a *= a;

		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 2e5 + 7;
const long long INF = LLONG_MAX;
int a[N];

int dp[N][3][2];
int n;

int go(int i, int f, int f3)
{
	if (i < 0)
	{
		if (n % 2 == 0) return 0;
		if (f3) return -1e15;
		else return 0;
	}

	int &ans = dp[i][f][f3];
	if (ans != -1e16) return ans;

	int op1 = -1e15;
	int op2 = -1e15;
	int op3 = -1e15;

	if (f3) op1 = go(i - 1, f, 0);


	if (f == 1)
	{
		op2 = a[i] + go(i - 2, f, f3);
	}
	else
	{
		op2 = a[i] + go(i - 2, 0, f3);
		if ( i - 1 >= 0 ) op3 = a[i - 1] + go(i - 3, 1, f3);
	}
	return ans = max({op1, op2, op3});

}

void solve()
{
	cin >> n;
	loop(i, 0, n) cin >> a[i];

	loop(i, 0, n)
	{
		loop(j, 0, 3)
		{
			loop(k, 0, 2) dp[i][j][k] = -1e16;
		}
	}
	int ans;
	int f3 = 1;
	if (n % 2 == 0) f3 = 0;
	ans =  go(n - 1, 0, f3);
	cout << ans << endl;

	return;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



	cout << setprecision(9) << fixed;

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}


	return 0;
}

