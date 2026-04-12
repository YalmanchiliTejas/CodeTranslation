#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

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
        initialize();
    }

    void initialize(){
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

    int nCr(int n, int r){
        if(r > n || r < 0 || n < 0) return 0;
        if(n > MAX_N){
            MAX_N = n;
            initialize();
        }
        int a = fact[n];
        a = (a * invfact[r]) % mod;
        a = (a * invfact[n - r]) % mod;
        return a;
    }
};

signed main(){

    int N, M; cin >> N >> M;

    mat dp(N + 1, vec(N + 1, 0));
    REP(i, N + 1) dp[i][0] = 1;
    FOR(i, 1, N + 1){
        FOR(j, 1, i + 1){
            dp[i][j] = (dp[i - 1][j - 1] + (j + 1) * dp[i - 1][j]) % M;
        }
    }

    //2^i
    vec pow1(N * N + 1);
    pow1[0] = 1;
    FOR(i, 1, N * N + 1) pow1[i] = (pow1[i - 1] * 2) % M;

    //2^(2^i)
    vec pow2(N + 1);
    REP(i, N + 1) pow2[i] = fastpow(2, fastpow(2, i, M - 1), M);

    vec ways(N + 1, 0);
    REP(i, N + 1){
        REP(j, i + 1){
            int tmp = dp[i][j];
            tmp = (tmp * pow1[j * (N - i)]) % M;
            tmp = (tmp * pow2[N - i]) % M;
            ways[i] = (ways[i] + tmp) % M;
        }
    }

    Combination C(N, M);
    int ans = 0;
    REP(i, N + 1){
        if(i % 2 == 0) ans = (ans + C.nCr(N, i) * ways[i]) % M;
        else ans = (ans + C.nCr(N, i) * (M - ways[i])) % M;
    }
    cout << ans;
    
    return 0;
}