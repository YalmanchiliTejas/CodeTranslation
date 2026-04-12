#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

struct Combination{
    vector<long long> _fac,_finv,_inv;
    const int m = MOD;

    Combination(int sz) : _fac(sz),_finv(sz),_inv(sz){
        _fac[0] = _fac[1] = 1;
        _finv[0] = _finv[1] = 1;
        _inv[1] = 1;
        for(int i = 2; i <= sz; i++){
            _fac[i] = _fac[i-1]*i%m;
            _inv[i] = m-_inv[m%i]*(m/i)%m;
            _finv[i] = _finv[i-1]*_inv[i]%m;
        }
    }

    inline long long fac(int n){return _fac[n];}
    inline long long inv(int n){return _inv[n];}
    inline long long finv(int n){return _finv[n];}

    long long comb(int n,int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return _fac[n]*(_finv[k]*_finv[n-k]%m)%m;
    }
};

int main(){
    int N,M,K; cin >> N >> M >> K;
    Combination C(200010);
    ll ans = 0;
    repr(i,1,M){
        ans += (ll)N*N*(M-i)*i%MOD;
        ans %= MOD;
    }
    repr(i,1,N){
        ans += (ll)M*M*(N-i)*i%MOD;
        ans %= MOD;
    }
    ans *= C.comb(N*M-2,K-2);
    ans %= MOD;
    cout << ans << endl;
}
