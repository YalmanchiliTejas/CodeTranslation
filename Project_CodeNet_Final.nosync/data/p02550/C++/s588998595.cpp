#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main(){
	ll n,x,m;cin>>n>>x>>m;
	map<ll,int>mp;
	map<ll,ll>mp_sum;
	ll a=x;
	int cnt=0;
	ll sum=0;
	while(1){
		cnt++;
		mp[a]=cnt;
		mp_sum[a]=sum;
		sum+=a;
		if(cnt==n){
			cout<<sum<<endl;
			return 0;
		}
		a=(a*a)%m;
		if(mp.count(a)){
			int s=(cnt+1)-mp[a];
			ll ans=mp_sum[a];
			n-=mp[a]-1;
			ll d=sum-mp_sum[a];
			ans+=(n/s)*d;
			n%=s;
			rep(i,n){
				ans+=a;
				a=(a*a)%m;
			}
			cout<<ans<<endl;
			return 0;
		}
	}
}