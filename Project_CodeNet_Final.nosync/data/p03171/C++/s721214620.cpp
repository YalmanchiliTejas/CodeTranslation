#include <bits/stdc++.h>
using namespace std;

#define int             long long int
#define ld              long double
#define ff              first
#define ss              second
#define mp              make_pair
#define pb              push_back
#define endl            "\n"

#define si              set <int>
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

const int N = 3e5 + 7;
vector <vi > adj;
bool vis[N];
int a[3005];
int dp[3005][3005][3];

int help(int s, int e, int player) {
	if (s > e) return 0;

	if (dp[s][e][player] != -1) return dp[s][e][player];

	if (player == 1) {
		int op1 = a[s] + help(s + 1, e, 2);
		int op2 = a[e] + help(s, e - 1, 2);
		return dp[s][e][player] = max(op1, op2);
	}

	int op1 = help(s + 1, e, 1) - a[s];
	int op2 = help(s, e - 1, 1) - a[e];
	return dp[s][e][player] = min(op1, op2);

}

void solve()
{
	int n;
	cin >> n;
	mset(dp, -1);
	loop(i, 0, n) cin >> a[i];
	cout << help(0, n - 1, 1) ;
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