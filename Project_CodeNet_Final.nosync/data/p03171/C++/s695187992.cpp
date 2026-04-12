#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pll         pair<ll,ll>
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mode        998244353
#define mod         1000000007
#define inf         1000000000000000000LL
#define vl          vector<ll>
#define F           first
#define S           second
#define db          long double
#define sz(x)       (ll)x.size()
#define fix(n)      cout<<fixed<<setprecision(n)
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define all(x)      x.begin(),x.end()
#define mset(x)     memset(x,0,sizeof x)
#define pi          3.14159265358979323

ll dp[3003][3003];

void solve()
{
       ll n;
       cin>>n;
       vector<ll>a(n);
       rep(i,0,n) cin>>a[i];
       for(ll l=n-1; l>=0; l--){
              for(ll r=l; r<n; r++){
                     if(l==r) dp[l][r] = a[l];
                     else{
                            dp[l][r] = max(a[l] - dp[l+1][r], a[r] -dp[l][r-1]);
                     }
              }
       }
       cout<<dp[0][n-1]<<endl;
}



int main() {
	ll T = 1;
	speed_up
	//cin>>T;
	while(T--)
	    solve();
	return 0;
}
