#include <bits/stdc++.h>
using namespace std;

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int                                       long long
#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)
#define rlop(i,e,s)                               for(int i=e;i>=s;i--)
#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;
#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;

#define endl                                      '\n'
#define ff                                        first
#define ss                                        second
#define pii                                       pair<int,int>

#define pb                                        push_back
#define all(v)                                    v.begin(),v.end()

#define bug(...)                                  __f (#__VA_ARGS__, __VA_ARGS__)
#define rtn                                       if(0)return;
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { rtn cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{	rtn
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

const int N = 3e6 + 7, M = 1000000007, inf = INT_MAX;
const long long INF = LLONG_MAX;

int n, Q;
int arr[N + 2];
int dp[N][2][2];
int get(int id, int f, int f3)
{
	if ( id < 0 )
	{
		if (n % 2 == 0) return 0;
		if (f3) return -1e15;
		return 0;
	}

	int &mafia = dp[id][f][f3];
	if (mafia != -1) return mafia;

	int c = -1e15;
	if (n & 1 and f3) c = get(id - 1, f, 0);
	int a = -1e15, b = -1e15;
	if (f)
	{
		a = arr[id] + get(id - 2, 1, f3);
	}
	else
	{
		a = arr[id] + get(id - 2, 0, f3);
		if ( id - 1 >= 0 ) b = arr[id - 1] + get(id - 3, 1, f3);
	}
	a = max(a, c);
	return mafia = max(a, b);
}

void solve()
{
	cin >> n;
	lop(i, 0, n) cin >> arr[i];
	memset(dp, -1, sizeof dp);

	int res = -INF;
	int x = 0;
	if (n & 1) x = 1;
	res = max(res,  get(n - 1, 0, x));
	cout << res << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);

	int test = 1;
	// cin >> test;

	// cout << setprecision(9) << fixed;
	// clock_t z = clock();
	while (test--)solve();
	// cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}



