#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define fi first
#define se second
#define sz(A) (int)(A.size())
#define all(x) (x).begin(),(x).end()
#define caset int ___T; cin>>___T; for(int cs=1;cs<=___T;cs++)
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
const ll mod=1e9+7;
const int Max = 1e6+10;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
void solve(){
	int n;
	cin>>n;
	VI a(n+1);
	rep(i,1,n+1){
		cin>>a[i];
	}
	vector<ll> dp(n+1,0);
	dp[1] = 0;
	vector<ll> prefix(n+1);
	prefix[1] = a[1];
	for(int i=3;i<=n;i+=2){
		prefix[i] = prefix[i-2]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		}else{
			dp[i] = a[i] + dp[i-2];
			dp[i] = max(dp[i],prefix[i-1]);
		}
	}
	cout<<dp[n];
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//caset{
		solve();
	//}
  	return 0;
}




