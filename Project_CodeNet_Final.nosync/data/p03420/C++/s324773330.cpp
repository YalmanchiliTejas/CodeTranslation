#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

using namespace std;

int main(){
	long int N, K, ans = 0, i;
	scanf("%ld %ld", &N, &K);

	for (i = K + 1; i <= N; i++){
		if (N%i >= K){
			ans = ans + (N / i)*(i - K) + ((N%i) - K + 1);
		}
		else{
			ans = ans + (N / i)*(i - K);
		}
	}
	if (K == 0){
		printf("%lu\n", N*N);
	}
	else{
		printf("%ld\n", ans);
	}
	return 0;
}