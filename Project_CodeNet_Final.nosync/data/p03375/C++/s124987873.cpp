#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

typedef long long ll;

const ll MAX_N=3e3;

ll N,M;

ll fact[MAX_N+1];

ll mpw(ll n,ll m,ll mod=M){
	if (m==0){
		return 1;
	}
	ll ret=mpw(n,m/2,mod);
	ret*=ret;
	ret%=mod;
	if (m%2==1){
		ret*=n;
		ret%=mod;
	}
	return ret;
}

ll inv(ll n,ll mod=M){
	return mpw(n,mod-2,mod);
}

ll comb(ll n,ll m){
	return fact[n]*inv(fact[m])%M*inv(fact[n-m])%M;
}

ll dp[MAX_N+1][MAX_N+1];

int main(){
	cin>>N>>M;
	fact[0]=1;
	FOR(i,1,N+1){
		fact[i]=(fact[i-1]*i)%M;
	}
	FOR(i,1,N+1){
		dp[0][i]=0;
	}
	REP(i,N+1){
		dp[i][0]=1;
	}
	FOR(i,1,N+1){
		FOR(j,1,N+1){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%M+dp[i-1][j]*j%M;
			dp[i][j]%=M;
		}
	}
	REP(i,N+1){
		ll p2=mpw(2,N-i),pj2=1;
		ll pp2=mpw(2,mpw(2,N-i,M-1));
		REP(j,i+1){
			dp[i][j]*=pj2*pp2%M;
			dp[i][j]%=M;
			pj2*=p2;
			pj2%=M;
		}
	}
	ll ans=0;
	REP(i,N+1){
		ll s=0;
		REP(j,i+1){
			s+=dp[i][j];
			s%=M;
		}
		ll sign=(i%2) ? -1 : 1;
		ans+=sign*((comb(N,i)*s)%M);
		ans+=M;
		ans%=M;
	}
	cout<<ans<<endl;
	return 0;
}