#include<cstdio>
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;

ll RepeatSquaring(ll N, ull P){
	if(P == 0 || N == 1) return 1;
	if(N == -1) return P & 1 ? -1 : 1;
	if(!(P & 1)){
		ll t = RepeatSquaring(N, P >> 1);
		return t*t %MOD;
	}
	return N*RepeatSquaring(N, P - 1) % MOD;
}
int main(){
    unsigned N;
    scanf("%u", &N);
    ull square = 0, tmp, sum = 0;
    for(unsigned i = 0; i < N;i++){
        scanf("%llu", &tmp);
        square = (tmp*tmp %MOD + square) %MOD;
        sum = (sum + tmp) %MOD;
    }
    printf("%llu\n", (sum*sum %MOD + MOD - square)%MOD *RepeatSquaring(2, MOD-2) %MOD);
	return 0;
}