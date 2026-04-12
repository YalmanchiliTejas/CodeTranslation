#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=200005;
const ll MOD=1000000007;
ll fac[MAX],finv[MAX],inv[MAX];
ll ans;
void COMinit(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<MAX;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll COM(ll i,ll j){
	if(i<j) return 0;
	if(i<0||j<0) return 0;
	return fac[i]*(finv[j]*finv[i-j]%MOD)%MOD;
}
int main(void){
	COMinit();
    ll n,m,k; cin>>n>>m>>k;
    //cout<<"AA"<<endl;
    for(int i=1;i<=n-1;i++){
		if(n*m-2>=MOD){
		}else{
			ans=(ans+i*m*m*(n-i)*COM(n*m-2,k-2))%MOD;
		}
		//cout<<ans<<endl;
	}
	for(int i=1;i<=m-1;i++){
		if(n*m-2>=MOD){
		}else{
			ans=(ans+i*n*n*(m-i)*COM(n*m-2,k-2))%MOD;
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
