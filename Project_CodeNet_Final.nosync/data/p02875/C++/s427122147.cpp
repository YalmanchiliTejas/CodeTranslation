#include <bits/stdc++.h>
using namespace std;
long long fac[10000010], finv[10000010], inv[10000010]; 
long long P = 998244353;
long long Pow(long long int a, long long n) {
	long long tmp = a; 
	long long pow = n;
	long long Q = 1;  
  	while(pow > 0){
		if(pow & 1){
			Q *= tmp; Q %= P; 
		}
		tmp = tmp * tmp % P; 
     		pow >>= 1; 
  	}
	return Q;
} 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 10000005; i++) {
        fac[i] = fac[i - 1] * i % P;
        inv[i] = P - inv[P % i] * (P / i) % P;
        finv[i] = finv[i - 1] * inv[i] % P;
    }
}
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % P) % P;
}
int main(){
	int N; cin >> N; 
	COMinit(); 
	long long pow[5000010] = {}; 
	pow[0] = 1; 
	for(int i = 1; i <= N/2; i++){
		pow[i] = pow[i-1] * 2 % P; 
	}
	long long ans = Pow(3, N); 
	for(int i = 0; i < N/2; i++){
		long long tmp = 2 * COM(N, i) * pow[i] % P; 
		ans += P - tmp; 
		if(ans >= P) ans -= P; 
	}
	cout << ans << endl;  
}