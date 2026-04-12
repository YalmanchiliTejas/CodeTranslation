#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include<iomanip>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,n) for(int i=1,i##_len=(n);i<=i##_len;++i)
#define rrep(i,n) for(int i=((int)((n)-1));i>=0;--i)
#define rreps(i,n) for(int i=((int)(n));i>0;--i)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 4545
#endif

typedef long long int lli;
using namespace std;
typedef pair<int, int> ii;
typedef priority_queue<int, vector<int>, greater<int> > heapq;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define int long long int
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

const lli MOD = 1000000007LL;

inline lli mod_add(lli x, lli y) {
    return (x + y) % MOD;
}

inline lli mod_mul(lli x, lli y) {
    return (x * y) % MOD;
}

inline lli mod_sub(lli x, lli y) {
    return x - y >= 0 ? (x - y) % MOD : (x - y + MOD) % MOD;
}

inline lli mod_pow(lli x, lli y) {
    lli ret = 1;
    while (y > 0) {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y = y >> 1;
    }
    return ret;
}

inline lli mod_inv(lli x) {
    return mod_pow(x, MOD - 2);
}

inline lli mod_div(lli x, lli y) {
    return x * mod_inv(y) % MOD;
}

#define MAX_FAC 200001
lli fac[MAX_FAC], finv[MAX_FAC];
void init_fac() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAX_FAC; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        finv[i] = finv[i - 1] * mod_inv(i) % MOD;
    }
}
inline lli com(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main() {
    int N, M, K; cin >> N >> M >> K;
    init_fac();

    int combi = com(mod_mul(N, M) - 2, K - 2);
    int ans = 0;
    // X座標から求める
    reps(d, M - 1) {
        int xCombi = mod_mul(mod_mul(M - d, N), N);
        ans = mod_add(ans, mod_mul(d, xCombi));
    }
    // Y座標から求める
    reps(dy, N - 1) {
        int yCombi = mod_mul(mod_mul(N - dy, M), M);
        ans = mod_add(ans, mod_mul(dy, yCombi));
    }

    cout << mod_mul(ans, combi) << endl;
    return 0;
}
