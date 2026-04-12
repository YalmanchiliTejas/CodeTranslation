#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
//const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

const int N=3005;
ll f[N][N],c[N][N],ans = 0;
long long modpow(long long a, long long n, ll mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, mod;
    cin >> n >> mod;
    f[0][0] = c[0][0] = 1;
    for(int i=1;i<=n+1;i++){
    	for(int j=0;j<=i;j++){
    		f[i][j] = ( j ? (f[i-1][j-1] + f[i-1][j] * j)%mod : 0 );
    		c[i][j] = ( j ? (c[i-1][j-1] + c[i-1][j])%mod : 1);
    	}
    }
    for(int i=0;i<=n;i++){
    	ll ret = 0, maki = modpow(2LL, n-i, mod), k = 1;
    	for(int j=0;j<=i;j++){
    		ret += (f[i+1][j+1] * k)%mod;
    		ret %= mod;
    		(k *= maki) %= mod;
    	}
    	if(i&1) ans -= (((c[n][i] * modpow(2LL, modpow(2LL,n-i,mod-1), mod))%mod) * ret) %mod;
    	else ans += (((c[n][i] * modpow(2LL, modpow(2LL,n-i,mod-1), mod))%mod) * ret) %mod;
    	ans %= mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}