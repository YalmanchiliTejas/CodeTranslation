#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


ll comb[3005][3005];
int n;
ll MOD;
// stl_sec(i,j) means tne number of ways divide exactly i elements divide by j groups 
ll stl_sec[3005][3005];
// ways2(i,j) means the number of ways "some" of i elements divide by j groups
ll ways2[3005][3005];
ll ways[3005];
ll twop[20000005];

ll mod_pow(ll x,ll n,ll m=MOD){
	ll ans=1;
	while(n>0LL){
		if(n&1LL)ans=ans*x%m;
		x=x*x%m;
		n>>=1LL;
	}
	return ans;
}

void init(){
	twop[0]=1;
	for(int i=1;i<=20000004;i++){
		twop[i]=twop[i-1]*2LL%MOD;
	}
	comb[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=1;j<i;j++){
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
		}
		comb[i][0]=1;
		comb[i][i]=1;
	}
}

int main(void){
	scanf("%d%lld",&n,&MOD);
	init();
	stl_sec[0][0]=1;
	for(int i=0;i<=n+1;i++){
		for(int j=1;j<=i;j++){
			stl_sec[i][j]=(stl_sec[i-1][j-1]+stl_sec[i-1][j]*j)%MOD;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			ways2[i][j]=stl_sec[i+1][j+1]*twop[(n-i)*j]%MOD;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			ways[i]=(ways[i]+ways2[i][j])%MOD;
		}
	}
	ll ans=0;
	ll po=1;
	for(int i=0;i<=n;i++){
		ans+=((mod_pow(2,mod_pow(2,n-i,MOD-1LL))*comb[n][i]%MOD)*ways[i]%MOD)*po;
		if(ans<0LL)ans+=MOD;
		ans%=MOD;
		po*=-1;
	}
	printf("%lld\n",ans);
	return 0;
}