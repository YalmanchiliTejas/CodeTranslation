#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

const int MOD = 1000000007;

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
     a -= MOD;
 }
}

inline void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
     a += MOD;
 }
}

inline int mul(int a, int b) {
    return (long long) a * b % MOD;
}

inline int power(int a, int b) {
    int res = 1;

    while (b > 0) {
        if (b & 1) res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }

    return res;
}

inline int inverse(int x) {
    return power(x, MOD - 2);
}

const int MK = 10010;

int dp[MK][100][2];
int D;

int main() {
    string k; cin >> k;
    dp[0][0][0] = 1;
    int D; cin >> D;

    int sz = k.size();
    rep(i, sz) {
        int c = k[i] - '0';

        //smaller
        rep(j, D) {
            rep(k, 10) {
                add(dp[i+1][(j+k)%D][1], dp[i][j][1]);
            }
        }

        rep(j, D) {
            for (int k = 0; k <= c; ++k) {
                add(dp[i+1][(j+k)%D][(k < c)], dp[i][j][0]);
            }
        }
    }

    int ans = MOD - 1;
    add(ans, dp[sz][0][0]);
    add(ans, dp[sz][0][1]);

    cout << ans << endl;

    return 0;
}