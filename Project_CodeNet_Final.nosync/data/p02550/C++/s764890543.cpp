#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,x,m;
	scanf("%lld %lld %lld",&n,&x,&m);
	ll sc=0;
	ll c=  0;
	vector<ll> f(m);
	ll k = x;
	ll ini;
	ll cont = 0;
	while(1){
		if(f[k])
			break;
		f[k] = 1;
		k = k*k%m;
	}
	ini = k;
	k = x;
	ll ans = 0;
	while(k!=ini && n--){
		ans += k;
		k=k*k%m;
		cont++;
	}
	if(n == 0){
		printf("%lld\n",ans );
		return 0;
	}
	k = ini;
	cont = 0;
	sc = 0;
	do{
		cont++;
		sc+=k;
		k=k*k%m;
	}while(k!=ini);
	ans += (n/cont)*sc;
	n = n%cont;
	while(n--){
		ans += k;
		k = k*k%m;
	}
	printf("%lld\n", ans);
	return 0;
}