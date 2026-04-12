#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

struct mint {
    ll x;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {if ((x+=a.x)>=MOD) x-=MOD; return *this;}
    mint& operator-=(const mint a) {if ((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
    mint& operator*=(const mint a) {(x*=a.x)%=MOD; return *this;}
    mint operator+(const mint a) const {mint res(*this); return res+=a;}
    mint operator-(const mint a) const {mint res(*this); return res-=a;}
    mint operator*(const mint a) const {mint res(*this); return res*=a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(MOD-2);}
    mint& operator/=(const mint a) { return (*this) *= a.inv();}
    mint operator/(const mint a) const {mint res(*this); return res/=a;}
};

const int cmax = 200010;
mint fac[cmax],finv[cmax],inv[cmax];

void com_init() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2; i<cmax; i++) {
        fac[i]=fac[i-1]*i;
        inv[i]=-inv[MOD%i]*(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}

ll com(int n, int k) {
    if (n<k) return 0;
    if (n<0||k<0) return 0;
    mint ret=fac[n]*finv[k]*finv[n-k];
    return ret.x;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;

	mint a[2 * N + 1];
	a[2] += 1;
	for(int i = 3; i <= n * m; i++) {
		a[i] = a[i - 1] * 2 - a[i - 2] + i - 1;
	}

	com_init();
	mint ans = (a[n] * m * m + a[m] * n * n) * com(n * m - 2, k - 2);
	cout << ans.x << endl;
}
