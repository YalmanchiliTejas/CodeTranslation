#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define U 998244353
#define N 1000005
#define int long long
#define sz(c) (int)c.size()
#define fr first
#define ll long long 
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define r0 return 0;
#define endl '\n'
#define INF (int)1e15
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	int TESTS=1;
	// cin>>TESTS;
	while(TESTS--)
	{   
		int n;
		cin >> n;
		int a[n+1];
		rep(i,1,n+1) cin >> a[i];
		int dp[n+1][n+1];
		rep(i,0,n+1){
			rep(j,0,n+1){
				dp[i][j] = -INF;
			}
		}
		rep(i,1,n+1) dp[i][i] = a[i];
		rep(gap,1,n){
			rep(i,1,n-gap+1){
				int j = i+gap;
				dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
			}
		}
		cout<<dp[1][n];
	}
}