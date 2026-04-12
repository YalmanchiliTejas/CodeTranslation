#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL mod = 1e9+7;

LL modinv(LL x){
	LL m=mod, u=1, v=0;
	while(m){
		LL t=x/m;
		x-=t*m; swap(x,m);
		u-=t*v; swap(u,v);
	}
	u%=mod;
	if(u<0) u+=mod;
	return u;
}

int main(){
	int N;
	cin >> N;
	vector<LL> A(N);
	rep(i,N) cin >> A[i];
	LL sum=0;
	rep(i,N) (sum+=A[i])%=mod;
	LL ans=0;
	rep(i,N){
		ans+=(sum-A[i])*A[i]%mod;
		ans%=mod;
	}
	ans*=modinv(2);
	ans%=mod;
	while(ans<0) ans+=mod;
	cout << ans << endl;

	return 0;
}