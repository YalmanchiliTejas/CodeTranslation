#include <bits/stdc++.h>

typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;	

const ll MOD=1e9+7,MAX_N=100;

ll N,h[MAX_N];

ll memo[MAX_N][MAX_N*2];
vector<ll> hei;

ll mpw(ll n,ll m){
	if (m==0){
		return 1;
	}
	ll ret=mpw(n,m/2);
	ret*=ret;
	ret%=MOD;
	if (m&1){
		ret*=n;
		ret%=MOD;
	}
	return ret;
}

ll dfs(ll n,ll m){
	if (memo[n][m+1]!=-1){
		return memo[n][m+1];
	}
	ll ret=0;
	if (m%2==0 && hei[m/2+1]-hei[m/2]<=1){
		ret=0;
	}else if (n==N-1){
		if (m==-1){
			ret=2;
		}else{
			if (m&1){
				ret=mpw(2,h[n]-hei[m/2+1]);
			}else{
				ret=mpw(2,h[n]-hei[m/2+1])*((mpw(2,hei[m/2+1]-hei[m/2]-1)+MOD-1)%MOD)%MOD*2%MOD;
			}
		}
	}else if (m==-1){
		if (h[n+1]<=h[n]){
			ret=dfs(n+1,-1)*2%MOD;
		}else{
			ret=dfs(n+1,-1)*2%MOD;
			ll x=lower_bound(hei.begin(),hei.end(),h[n])-hei.begin(),y=lower_bound(hei.begin(),hei.end(),h[n+1])-hei.begin();
			REP(i,(y-x)*2){
				ret+=dfs(n+1,x*2+i-1)*2%MOD;
				ret%=MOD;
			}
		}
	}else{
		if (m%2){
			if (h[n+1]>hei[m/2+1]){
				ret=dfs(n+1,m)*mpw(2,max(h[n]-h[n+1],0ll))%MOD;
			}else{
				ret=mpw(2,h[n]-hei[m/2+1])*dfs(n+1,-1)%MOD;
			}
		}else{
			if (h[n+1]>=hei[m/2+1]){
				ret=dfs(n+1,m)*mpw(2,max(h[n]-h[n+1],0ll))%MOD;
			}else{
				ret=mpw(2,h[n]-hei[m/2+1])*((mpw(2,hei[m/2+1]-hei[m/2]-1)+MOD-1)%MOD)%MOD*2%MOD*dfs(n+1,-1)%MOD;
			}
		}
	}
	return memo[n][m+1]=ret;
}

		
int main(){
	cin>>N;
	REP(i,N){
		cin>>h[i];
		hei.push_back(h[i]);
	}
	hei.push_back(0);
	sort(hei.begin(),hei.end());
	hei.erase(unique(hei.begin(),hei.end()),hei.end());
	memset(memo,-1,sizeof(memo));
	ll ans=dfs(0,-1);
	ll x=lower_bound(hei.begin(),hei.end(),h[0])-hei.begin();
	REP(i,x*2-1){
		ans+=dfs(0,i);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}