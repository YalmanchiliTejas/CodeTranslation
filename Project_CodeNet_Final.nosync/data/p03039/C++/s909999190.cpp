#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int64 modpow(int64 a, int64 r){
    if(r == 0)return 1;
    if(r % 2 == 0){
        return modpow(a * a % MOD, r / 2) % MOD;
    }else{
        return modpow(a, r - 1) * a % MOD;
    }
}

int64 modComb(int64 n, int64 r){
    r = min(r, n-r);
    int64 retval = 1;
    REP(i,r){
        retval = retval * (n - i) % MOD * modpow(i + 1, MOD-2) % MOD;
    }
    return retval;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,m,k;
    cin >> n >> m >> k;
    int64 pattern = modComb(n * m - 2, k - 2);
    int64 cnt1 = 0;
    FOR(i,1,n){
        cnt1 += i * (n - i);
        cnt1 %= MOD;
    }
    cnt1 = cnt1 * m % MOD * m % MOD * pattern % MOD;
    int64 cnt2 = 0;
    FOR(i,1,m){
        cnt2 += i * (m - i);
        cnt2 %= MOD;
    }
    cnt2 = cnt2 * n % MOD * n % MOD * pattern % MOD;
    ANS((cnt1 + cnt2) % MOD);
    return 0;
}