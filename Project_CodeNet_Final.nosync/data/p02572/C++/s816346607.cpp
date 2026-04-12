#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e5 + 5;
const int M = 21;
const int oo = 1e9 + 5;
const LL ooll = (LL)1e18 + 5;
const int MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng)

clock_t start = clock();

LL powermod(LL a, LL b) {
    LL pw = 1, mul = a, res = 1;
    while(pw <= b) {
        if (b & pw) res = (res * mul)%MOD;
        mul = (mul * mul)%MOD;
        pw <<= 1;
    }
    return res;
}

void solve() {
    LL n;
    cin >> n;
    LL sum = 0, sumsq = 0;
    while(n--) {
        LL x;
        cin >> x;
        sum += x; if (sum >= MOD) sum -= MOD;
        sumsq += (x * x)%MOD; if (sumsq >= MOD) sumsq -= MOD;
    }
    cout << ((((sum * sum)%MOD - sumsq)%MOD + MOD)%MOD * powermod(2, MOD-2))%MOD << '\n';
}

int main() {
    FASTIO;
    int T = 1;
    // cin >> T;
    for (int t=1;t<=T;++t) {
        solve();
    }
    // cerr << fixed << setprecision(10);
    // cerr << (clock() - start) / ((long double)CLOCKS_PER_SEC) << '\n';
    return 0;
} 