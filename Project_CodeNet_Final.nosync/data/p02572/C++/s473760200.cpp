#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i,k;
	ll N;
	ll ans=0;
	int ctr=0;
	const long long MOD=1e9+7;

	cin >> N;

	vector<ll> gv(N);
	vector<ll> s(N+1,0);

	rep(i,N) cin >> gv[i];
	for(i=N-1;i>0;i--) s[i-1]=(gv[i]+s[i])%MOD;

	for(i=0;i<N-1;i++){
		ans+=(gv[i]*s[i])%MOD;
	}
	
	cout << ans%MOD << endl;

	return 0;
}

