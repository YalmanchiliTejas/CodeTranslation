#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
LL N,M,K;
LL MOD=1e9+7;
LL c[500021];
LL rc[500021];
void init(){
	c[0]=1;
	rc[0]=1;
	REP(i,500011){
		c[i+1]=c[i]*(i+1);
		c[i+1]%=MOD;
	}
	LL now=MOD-2;
	LL ans=1;
	LL t=c[500010];
	while(now!=0){
		if(now%2==1){
			ans*=t;
			ans%=MOD;
		}
		now/=2;
		t*=t;
		t%=MOD;
	}
	rc[500010]=ans;
	for(int i=500009;i>=0;i--){
		rc[i]=rc[i+1]*(i+1);
		rc[i]%=MOD;
	}
	
}

int main(){
	init();
	cin>>N>>M>>K;
	LL ans=0;
	//LL now=((M*M-1)/2)%MOD;
	LL temp=1;
	REP(i,K-2){
		LL x=(N*M-2-i)%MOD;
		temp*=x;
		temp%=MOD;
	}
	temp*=rc[K-2];
	temp%=MOD;
	/*
	LL temp=c[N+M-2];
	temp*=rc[K-2];
	temp%=MOD;
	temp*=rc[N+M-2-(K-2)];
	temp%=MOD;
	*/
	REP(i,M-1){
		LL now=(i+1)*(LL)(i+2)/2;
		now%=MOD;
		LL a=(temp*now)%MOD;
		a%=MOD;
		a*=N;
		a%=MOD;
		a*=N;
		a%=MOD;
		ans+=a;
		ans%=MOD;
	}
	REP(i,N-1){
		LL now=(i+1)*(LL)(i+2)/2;
		now%=MOD;
		LL a=(temp*now)%MOD;
		a%=MOD;
		a*=M;
		a%=MOD;
		a*=M;
		a%=MOD;
		ans+=a;
		ans%=MOD;
	}
	
	
	cout<<ans<<endl;
}