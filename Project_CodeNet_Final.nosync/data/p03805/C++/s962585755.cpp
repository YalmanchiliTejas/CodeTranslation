#pragma GCC optimize ("O2")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FFOR(i, a, b) FOR(i, a, b+1)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) FOR(i, 1, n+1)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define LEN(x) (int)(x).size()
#define DUMP(x) cerr<<__LINE__<<' '<<#x<<"="<<(x)<<endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;
using lint = long long;
using pii =  pair<int, int>;
using pll =  pair<lint, lint>;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vector<T>>;
template <typename T> inline bool chmax(T &a, T b){if(a<b){a = b; return true;} return false;}
template <typename T> inline bool chmin(T &a, T b){if(a>b){a = b; return true;} return false;}

const double PI = acos(-1);
constexpr lint ten(int n) {return n==0 ? 1 : ten(n-1)*10;}

class Task{
public:
    void solve(istream& in, ostream& out){
        int N, M;
        in>>N>>M;
        vvc<int> G(N);
        REP(i, M){
            int a, b;
            in>>a>>b;
            a--, b--;
            G[a].pb(b);
            G[b].pb(a);
        }
        vvc<int> dp(1<<N, vc<int>(N, 0));
        dp[1][0] = 1;
        FOR(mask, 1, 1<<N) REP(j, N){
            if(not dp[mask][j]) continue;
            for(auto& u : G[j]){
                if((mask>>u&1)==0){
                    dp[mask|1<<u][u] += dp[mask][j];
                }
            }
        }
        int ans = 0;
        REP(j, N) ans += dp[(1<<N)-1][j];
        out<<ans<<'\n';
    }
};

int main(){
    istream& in(cin);
    ostream& out(cout);
    ios_base::sync_with_stdio(false);
    in.tie(nullptr), out.tie(nullptr);
    Task solver;
    solver.solve(in, out);
    return 0;
}