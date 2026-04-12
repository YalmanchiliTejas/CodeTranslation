#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define all(n) (n).begin(),(n).end()
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}


const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	COMinit();
	ll ans=0;
	for(int i=1;i<n;i++){
		ans+=((((n-i)*m*m)%MOD)*COM(n*m-2,k-2)%MOD)*i;
		ans%=MOD;
	}

	for(int i=1;i<m;i++){
		ans+=((((m-i)*n*n)%MOD)*COM(n*m-2,k-2)%MOD)*i;
		ans%=MOD;
	}

	cout << ans << endl;
}