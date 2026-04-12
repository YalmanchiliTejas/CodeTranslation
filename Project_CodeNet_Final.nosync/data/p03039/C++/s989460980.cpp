#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 200010;
ll inv[MAX],fact[MAX],fi[MAX],mod = 1000000007;
void inverse(){
	int i;
	inv[1] = 1;
	for(i=2;i<MAX;i++){
		inv[i] = mod - (mod/i)*inv[mod%i]%mod;
	}
	fact[0] = fi[0] = 1;
	for(i=1;i<MAX;i++){
		fact[i] = fact[i-1]*i%mod;
		fi[i] = (fi[i-1]*inv[i])%mod;
	}
}

ll comb(int n,int k){
	if(n<0 || k<0 || n<k){
		return 0;
	}else{
		return fact[n]%mod*fi[k]%mod*fi[n-k]%mod;
	}
}
int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	inverse();
	cout << (n + m)*inv[3]%mod*comb(k,2)%mod*comb(n*m,k)%mod << endl;
}