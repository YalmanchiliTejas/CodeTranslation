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

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[0].size()){ cout << m[i][j] << ","; } cout << endl; }}

int modpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return a;
}

signed main(){

    int N; cin >> N;
    vec h(N + 1, 1); REP(i, N) cin >> h[i + 1];
    int mod = 1000000007;

    set<int> s;
    REP(i, N + 1) s.insert(h[i]);
    map<int, int> m;
    vec v(0);
    for(int i: s) v.push_back(i);
    int n = v.size();
    //REP(i, n) cout << v[i] << endl;

    mat dp(N + 1, vec(n + 1, 0));
    dp[0][n] = 1;
    REP(i, N){
        int j0 = Lower_bound(v, h[i]);
        int j1 = Lower_bound(v, h[i + 1]);
        if(j1 <= j0){
            REP(j, j1 + 1){
                dp[i + 1][j] = dp[i][j];
            }
            FOR(j, j1 + 1, n + 1){
                dp[i + 1][n] += 2 * dp[i][j];
                dp[i + 1][n] %= mod;
            }
        }else{
            REP(j, j0 + 1){
                dp[i + 1][j] = (dp[i][j] * modpow(2, h[i + 1] - h[i], mod)) % mod;
            }
            FOR(j, j0 + 1, j1 + 1){
                int tmp = ((modpow(2, v[j] - v[j - 1], mod) + mod - 1) * modpow(2, h[i + 1] - v[j], mod)) % mod;
                dp[i + 1][j] = (2 * dp[i][n] * tmp) % mod;
            }
            dp[i + 1][n] = (2 * dp[i][n]) % mod;
        }
    }

    //debug(dp);

    int ans = 0;
    REP(i, n + 1) ans = (ans + dp[N][i]) % mod;
    cout << ans;
    
    return 0;
}