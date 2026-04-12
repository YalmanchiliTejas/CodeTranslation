#include<bits/stdc++.h>
#define FOR0(i,n) for(ll i=0;i<n;i++)
#define FOR1(i,n) for(ll i=1;i<=n;i++)
#define FORl(i,l,n) for(ll i=l;i<n;i++)
using namespace std;
#define pi pair<ll,ll>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define mst0(x) memset(x,0,sizeof(x));
#define vi vector<ll>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define sp <<" "<<
#define intmax 1e14
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

int main(){
	int n;
	cin >> n;
	ll a[n];
	FOR0(i,n) cin>>a[i];
	ll dp[n+1][n+1];
	memset(dp, -1, sizeof(dp));
	FOR1(i,n) dp[i][i] = a[i-1];
	//ll tot = accumulate(a, a+n);
	for (int len = 2; len <= n; len++){
		FOR1(i,n){
			int j = len + i - 1;
			if (j>n || j<=0) continue;
			dp[i][j] = max(a[i-1]-dp[i+1][j], a[j-1]-dp[i][j-1]);
		}
	}	
	// FOR1(i,n) {
	// 	FOR1(j,n) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	cout << dp[1][n] << endl;
}