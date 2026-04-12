#include <bits/stdc++.h>

using namespace std;

int main() {
	long long total, vet[212345], res=0, MOD = 1e9+7;
	int N;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%lld", &vet[i]);
		if (i) {
			vet[i] += vet[i-1];
		}
	}
	total = vet[N-1];

	for (int i = 0;i < N-1;i++) {
		if (!i){
			res = (vet[i] * ((total-vet[i])%MOD))%MOD;
		}else{
			res = res + (((vet[i]-vet[i-1])%MOD)*((total-vet[i])%MOD))%MOD;
		}
	}

	printf("%lld\n", res%MOD);

	return 0;
}