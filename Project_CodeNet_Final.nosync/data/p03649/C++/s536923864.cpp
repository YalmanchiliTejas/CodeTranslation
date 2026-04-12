#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=50;
const ll MAX_A=1e16+1000;
int N;
ll a[MAX_N];
int fmi(){
	int ret=0;
	FOR(i,1,N){
		if (a[i]>a[ret]){
			ret=i;
		}
	}
	return ret;
}
ll C(ll y){
	ll ret=0;
	REP(i,N){
		ret+=max((a[i]-y)/(N+1),0ll);
	}
	return ret;
}
int main(){
	cin>>N;
	REP(i,N)cin>>a[i];
	ll sm=0;
	REP(i,N)sm+=a[i];
	ll x=max(sm-N*N,0ll);
	ll ans=x;
	REP(i,N){
		a[i]+=x;
	}
	ll lb=-1,ub=MAX_A;
	while(ub-lb>1){
		ll mid=(lb+ub)>>1;
		if (C(mid)<=x){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	REP(i,N){
		x-=max((a[i]-ub)/(N+1),0ll);
		a[i]-=max((a[i]-ub)/(N+1),0ll)*(N+1);
	}
	REP(i,x){
		a[fmi()]-=N+1;
	}
	for(;;){
		int inx=fmi();
		if (a[inx]<=N-1){
			break;
		}else{
			a[inx]-=N;
			REP(i,N){
				if (i!=inx){
					a[i]++;
				}
			}
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}