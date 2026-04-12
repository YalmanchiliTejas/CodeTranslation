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

    int N; cin >> N;
    vec a(N); readv(a);

    mat dp(N + 1, vec(N + 1));
    REP(i, N + 1) dp[i][N - i] = 0;

    IREP(t, N){
        if(t % 2 == 0){
            REP(i, t + 1){
                int j = t - i;
                dp[i][j] = max(a[i] + dp[i + 1][j], a[N - 1 - j] + dp[i][j + 1]);
            }
        }else{
            REP(i, t + 1){
                int j = t - i;
                dp[i][j] = min(-a[i] + dp[i + 1][j], -a[N - 1 - j] + dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0];
    
    return 0;
}