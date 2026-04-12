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



void solve()
{
       ll n;
       cin>>n;
       ll h[n];
       rep(i,0,n) cin>>h[i];
       ll ans=1, mx=h[0];
       rep(i,1,n)
       {
              if(h[i]>=mx) ans++;
              mx = max(mx, h[i]);
       }
       cout<<ans;
}


int main() {
	ll T = 1;
	speed_up
	//cin>>T;
	while(T--)
	    solve();
	return 0;
}
