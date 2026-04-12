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
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}


signed main(){

    string K; cin >> K;
    int D; cin >> D;
    int N = K.size();
    int mod = 1000000007;

    vector<mat> dp(N + 1, mat(D, vec(2, 0)));
    dp[0][0][0] = 1;
    REP(i, N){
        int n = K[i] - '0';
        REP(j, n){
            REP(k, D){
                dp[i + 1][(k + j) % D][1] += dp[i][k][0] + dp[i][k][1];
                dp[i + 1][(k + j) % D][1] %= mod;
            }
        }
        REP(k, D) REP(l, 2){
            dp[i + 1][(k + n) % D][l] += dp[i][k][l];
            dp[i + 1][(k + n) % D][l] %= mod;
        }
        FOR(j, n + 1, 10){
            REP(k, D){
                dp[i + 1][(k + j) % D][1] += dp[i][k][1];
                dp[i + 1][(k + j) % D][1] %= mod;
            }
        }
    }
    
    cout << (dp[N][0][0] + dp[N][0][1] - 1 + mod) % mod;
    
    return 0;
}