#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PPi = pair<Pii, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;
using v_PPi = vector<PPi>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;



signed main(){

    int N; cin >> N;
    vec A(3 * N); cin >> A;
    REP(i, 3 * N) A[i]--;

    mat dp(N, vec(N, -INF));
    vec dpMAX(N, -INF);
    int offset = 0;
    dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
    dpMAX[A[0]] = 0;
    dpMAX[A[1]] = 0;
    int allMAX = 0;

    REP(i, N - 1){
        vec v({A[3 * i + 2], A[3 * i + 3], A[3 * i + 4]});
        Sort(v);

        v_PPi ls;
        if(v[0] == v[2]){
            offset++;
            continue;
        }else if(v[0] == v[1]){
            REP(k, N){
                ls.pb(PPi(Pii(k, v[2]), dp[k][v[0]] + 1));
            }
        }else if(v[1] == v[2]){
            REP(k, N){
                ls.pb(PPi(Pii(k, v[0]), dp[k][v[1]] + 1));
            }
        }
        REP(k, 3){
            ls.pb(PPi(Pii(v[(k + 1) % 3], v[(k + 2) % 3]), dp[v[k]][v[k]] + 1));

            REP(l, N) ls.pb(PPi(Pii(l, v[k]), dpMAX[l]));
            ls.pb(PPi(Pii(v[(k + 1) % 3], v[(k + 2) % 3]), allMAX));
        }


        for(PPi q: ls){
            chmax(dp[q.fi.fi][q.fi.se], q.se);
            chmax(dp[q.fi.se][q.fi.fi], q.se);
            chmax(dpMAX[q.fi.fi], q.se);
            chmax(dpMAX[q.fi.se], q.se);
            chmax(allMAX, q.se);
        }
    }

    int ans = 0;
    REP(i, N) REP(j, N) chmax(ans, dp[i][j] + (i == A[3 * N - 1] && j == A[3 * N - 1]));
    ans += offset;
    Out(ans);

    return 0;
}
