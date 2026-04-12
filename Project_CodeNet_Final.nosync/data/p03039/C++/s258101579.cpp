#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007

//累乗 O(log N)
long long power(long long x, int N){
	if(N == 1) return x;
	long long tmp = power(x, N/2);
	if(N%2 == 0) return tmp * tmp % MOD;
	else return tmp * tmp % MOD * x % MOD;
}

//逆元 O(log x)
long long inverse(long long x){
	return power(x, MOD-2);
}

LL N, M, K;
LL t = 1;
LL ans = 0;

int main(){
	cin >> N >> M >> K;
	for(LL i=0; i<K-2; i++){
		t *= N*M-2-i;
		t %= MOD;
		t *= inverse(i+1);
		t %= MOD;
	}
	for(LL i=0; i<N; i++){
		LL tmp = (N-1-i)*(N-i)/2;
		tmp %= MOD;
		tmp *= M;
		tmp %= MOD;
		tmp *= M;
		ans += tmp;
		ans %= MOD;
	}
	swap(N, M);
	for(LL i=0; i<N; i++){
		LL tmp = (N-1-i)*(N-i)/2;
		tmp %= MOD;
		tmp *= M;
		tmp %= MOD;
		tmp *= M;
		ans += tmp;
		ans %= MOD;
	}
	cout << (ans*t) % MOD << endl;
}
