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

const int inf = INT_MAX;
const long long INF = LLONG_MAX;

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
vector <vi > adj(N);

bool vis[N];

int dp[105][4][2];
int k;
vi num;
// f==0 -> the digits so far in the seq we have built are all equal to corresponding digits in
// given no and f==1 -> represents f = the number we are building has already become
// smaller than b
int go(int pos, int cnt, int f)
{
	if (pos == (sz(num)) and cnt == k) return 1;
	if (pos == sz(num)) return 0;
	if (cnt > k) return 0;
	int &ans = dp[pos][cnt][f];
	if (ans != -1) return ans;
	int lmt;
	if (f == 0) lmt = num[pos];
	else lmt = 9;
	int res = 0;

	loop(i, 0, lmt + 1)
	{
		int nf = f;
		int ncnt = cnt;
		if (i != 0)
			ncnt++;
		if (i < num[pos])
			nf = 1;
		res += go(pos + 1, ncnt, nf);
	}
	return ans = res;
}
void solve()
{
	string n;
	cin >> n >> k;
	//bug(n);
	loop(i, 0, sz(n))
	{
		int x = n[i] - '0';
		num.pb(x);
	}
	//print(num);
	mset(dp, -1);
	cout << go(0, 0, 0);

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
