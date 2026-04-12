#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const ll mod = 998244353; 

const int maxn = 10006; 

ll f[2][maxn]; 
char a[maxn], b[maxn]; 
ll fac[maxn*2]; 
ll ifac[maxn*2]; 
ll inv[maxn*2]; 

ll C(int x, int y) {
	return fac[x] * ifac[y] % mod * ifac[x-y] % mod; 
}

int main() {
	scanf( "%s", a ); 
	scanf( "%s", b ); 
	int n = strlen(a); 
	int s1=0, s2=0; 
	for (int i = 0; i < n; ++i) 
		if (a[i] == '1') {
			if (b[i] == '1') s1++; 
			else s2++; 
		}
	inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1; 
	for (int i = 2; i <= n*2; ++i) {
		inv[i] = mod / i * (mod - inv[mod % i]) % mod; 
		fac[i] = fac[i-1] * i % mod; 
		ifac[i] = ifac[i-1] * inv[i] % mod; 
	}
	memset(f, 0, sizeof(f)); 
	f[0][0] = 1; 
	int t = 0; 
	for (int i = 1; i <= s2; ++i) f[0][i] = f[0][i-1]*i*i % mod; 
	ll ans = f[0][s2] * C(s1+s2,s2) % mod * fac[s1] % mod * fac[s1] % mod; 
	//cout<<s1<<' '<<s2<<' '<<C(s1+s2,s2)<<' '<<ans<<endl; 
	for (int i = 1; i <= s1; ++i) {
		t = 1-t; 
		f[t][0] = 0; 
		for (int j = 1; j <= s2; ++j) {
			f[t][j] = (f[1-t][j]*i*j + f[t][j-1]*j*j) % mod; 
			//printf( "f[%d][%d]=%lld\n",i,j,f[t][j]); 
		}
		ans = (ans + f[t][s2] * C(s1+s2,i+s2) % mod * C(s1,i) % mod * fac[s1-i] % mod * fac[s1-i] % mod) % mod; 
	}
	cout<<ans<<endl; 
}
