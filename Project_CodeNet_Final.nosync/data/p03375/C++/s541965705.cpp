#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

ll MOD;

ll modpow(ll x,ll k){
	if(k==0)return 1;
	ll ret=modpow(x,k/2);
	ret*=ret; ret%=MOD;
	if(k%2==1){
		ret*=x;
		ret%=MOD;
	}
	return ret;
}

ll modpow2(ll x,ll k){
	if(k==0)return 1;
	ll ret=modpow2(x,k/2);
	ret*=ret; ret%=MOD-1;
	if(k%2==1){
		ret*=x;
		ret%=MOD-1;
	}
	return ret;
}

ll C[3005][3005];
ll D[3005][3005];
void init(){
	for(int i=0;i<3002;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=MOD)C[i][j]-=MOD;
		}
	}
	for(int k=1;k<3002;k++){
		D[k][1]=D[k][k]=1;
		for(int t=2;t<=k-1;t++){
			D[k][t]=t*D[k-1][t]+D[k-1][t-1];
			D[k][t]%=MOD;
		}
	}
}

int main(){
	ll n;
	cin>>n>>MOD;
	init();
	
	ll ret=modpow(2,modpow2(2,n));
	for(int k=1;k<=n;k++){
		ll x=0;
		ll z=modpow(2,n-k);
		ll y=1;
		for(int t=1;t<=k;t++){
			ll y_=y*(z+t); y_%=MOD;
			x+=y_*D[k][t];
			x%=MOD;
			y*=z; y%=MOD;
		}
		x*=C[n][k];
		x%=MOD;
		x*=modpow(2,modpow2(2,n-k));
		x%=MOD;
		if(k%2==0)ret+=x;
		else ret+=MOD-x;
	}
	cout<<ret%MOD<<endl;
}

