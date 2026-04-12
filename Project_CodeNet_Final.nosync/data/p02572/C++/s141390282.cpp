#include<bits/stdc++.h>

using namespace std;
#define PI              3.1415926536

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

bool f(int x, int y)
{
	return x > y;
}
void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }

void solve()
{



}




int32_t main()
{
	//c_p_c();
	FIO;

	// w(t)
	// {
	int n;
	cin >> n;
	int a[n];
	int i;

	for (i = 0; i < n; i++)
		cin >> a[i];

	int b[n];

	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			b[i] = a[i];
		}
		else if (i != 0)
		{
			b[i] = b[i - 1] % mod + a[i] % mod;
		}
	}

	int res = 0;
	for (i = n - 1; i >= 1; i--)
	{
		res %= mod;
		res += ((a[i] % mod) * (b[i - 1] % mod)) % mod;
	}
	cout << res % mod;
}


