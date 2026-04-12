#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define vv(type)		vector<vector<type>>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define db(x) 			cout<<x<<" "
#define db1(x) 			cout<<x<<'\n'
#define db2(x,y) 		cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) 		cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) 		for(int i=0;i<(n);++i)
#define repA(i,a,n) 	for(int i=a;i<=(n);++i)
#define repD(i,a,n) 	for(int i=a;i>=(n);--i)
#define so(a) 			sort(a.begin(),a.end())
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// to find all local maximaa and minima in O(n)
//	 for (int i=1;i<=n;i++)
//        {
//            if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
//           ans.push_back(p[i]);
//        }
int dx[] = { -1, 1, -1, 0, 0, -1, 1, 1 };
int dy[] = { -1, -1, 1, -1, 1, 0, 0, 1 };
int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}
int modular_expo(int x, int y, int m)
{
	int ans = 1;
	while (y)
	{
		if (y & 1)
			ans = (ans % m * x % m) % m;
		x = (x % m * x % m) % m;
		y /= 2;
	}
	return ans % m ;
}
int power(int x, int y)
{
	int ans = 1;
	while (y)
	{
		if (y & 1)
			ans = (ans * x);
		x *= x;
		y /= 2;
	}
	return ans;
}
int dp[3001][3001][2];

int winner(vi &a, int i, int j, int turn)
{
	if (i > j)	return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn)
		return dp[i][j][1] = max(a[i] + winner(a, i + 1, j, 0), a[j] + winner(a, i, j - 1, 0));
	else
		return dp[i][j][0] = min(winner(a, i + 1, j, 1), winner(a, i, j - 1, 1));
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	int sum = 0;
	rep(i, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	memset(dp, -1, sizeof(dp));
	int x = winner(a, 0, n - 1, 1);
	cout << 2 * x - sum;
}
int32_t main()
{
	solve();
	return 0;
}
