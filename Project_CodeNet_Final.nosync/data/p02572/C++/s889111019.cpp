#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define foreach(c,itr) for(__typeof(c)::iterator itr=c.begin();itr!=c.end();itr++)
typedef long long ll;
const ll mod=1000000000+7;
ll i,j;
ll kong=0;
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie();
    
    ll n;
    cin>>n;
    ll a[n+1];
    ll sum=0;
    rep(i,n){
    	cin>>a[i];
    	sum=(sum+a[i])%mod;
	}
	ll ans=0;
    for(i=0;i<n;i++){
    	sum-=a[i];
    	if(sum<0) sum+=mod;
		ll x=a[i]*sum;
		x%=mod;
		ans+=x;
		ans%=mod;
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}