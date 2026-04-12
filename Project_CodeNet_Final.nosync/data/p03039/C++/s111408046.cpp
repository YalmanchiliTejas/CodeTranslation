#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

llint n, m, k;

int main(void)
{
	cin >> n >> m >> k;
	
	llint C = 1;
	for(int i = 0; i < k-2; i++){
		C *= (n*m-2-i), C %= mod;
		C *= modpow(i+1, mod-2), C %= mod;
	}
	if(k == 2) C = 1;
	//cout << C << endl;
	
	llint ansx = 0;
	for(llint i = 1; i <= m; i++){
		ansx += (m-i)*i%mod, ansx %= mod;
	}
	ansx *= n*n%mod, ansx %= mod;
	ansx *= C, ansx %= mod;
	
	llint ansy = 0;
	for(llint i = 1; i <= n; i++){
		ansy += (n-i)*i%mod, ansy %= mod;
	}
	ansy *= m*m%mod, ansy %= mod;
	ansy *= C, ansy %= mod;
	
	cout << (ansx+ansy)%mod << endl;
	
	return 0;
}