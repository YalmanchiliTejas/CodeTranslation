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
		int n,s;
		cin >> n >> s;
		int a[n];
		rep(i,0,n) cin >> a[i];
		int dp[s]={};
		int ans = 0;
		rep(i,0,n){
			for(int j=s-a[i]; j>=1; j--){
				if(j+a[i]<s) dp[j+a[i]]=(dp[j+a[i]]+dp[j])%U;
				else if(j+a[i]==s) {
					ans += ((n-i)*(dp[j]%U))%U;
				}
				// trace(sz(dp[j]));
			}
			// cout << endl;
			if(a[i]<s) dp[a[i]]=(dp[a[i]]+i+1)%U;
			else if(a[i]==s){
				ans += (n-i)*(i+1);
				ans %= U;
			}
		}
		ans %=U;
		cout << ans;
	}
}