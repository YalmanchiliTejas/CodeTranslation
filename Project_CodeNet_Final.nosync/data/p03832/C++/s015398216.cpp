#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int fastpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return a;
}

class Combination
{
public:

    vec fact, invfact;
    int MAX_N, mod;

    Combination(int MAX_N, int mod): MAX_N(MAX_N), mod(mod) {
        fact = vec(MAX_N + 1);
        invfact = vec(MAX_N + 1);
        fact[0] = 1;
        FOR(i, 1, MAX_N + 1){
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invfact[MAX_N] = fastpow(fact[MAX_N], mod - 2, mod);
        IREP(i, MAX_N){
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
    }

    int comb(int n, int r){
        if(r > n || r < 0 || n < 0) return 0;
        int a = fact[n];
        a = (a * invfact[r]) % mod;
        a = (a * invfact[n - r]) % mod;
        return a;
    }
};

signed main(){

    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    mat dp(N + 1, vec(N + 1, 0));
    dp[A - 1][0] = 1;

    int mod = 1000000007;
    Combination Comb(N, mod);

    FOR(n, A, B + 1){
        REP(i, N + 1) dp[n][i] = dp[n - 1][i];
        REP(i, N + 1){
            int m = N - i;
            int c = 1;
            FOR(k, 1, m / n + 1){
                c *= Comb.comb(m - (k - 1) * n, n);
                c %= mod;
                if(C <= k && k <= D){
                    int tmp = (c * Comb.invfact[k]) % mod;
                    dp[n][i + n * k] += dp[n - 1][i] * tmp;
                    dp[n][i + n * k] %= mod;
                }
            }
        }
    }

    cout << dp[B][N];
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}