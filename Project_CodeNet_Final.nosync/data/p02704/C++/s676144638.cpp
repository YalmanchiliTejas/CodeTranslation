#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for(ll i=(ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
constexpr ll INF = 1ULL<<60;

int main() {
    ll n;
    cin >> n;
    // 0 → and, 1 → or
    vector<ll> s(n), t(n), u(n), v(n);
    REP(i, n) cin >> s[i];
    REP(i, n) cin >> t[i];
    REP(i, n) cin >> u[i];
    REP(i, n) cin >> v[i];

    vector<vector<ll>> ans(n, vector<ll>(n));
    REP(i, 64) {
        vector<ll> u2(n), v2(n);
        REP(j, n) u2[j] = !!(u[j]&1ULL<<i), v2[j] = !!(v[j]&1ULL<<i);
        
        vector<vector<ll>> used(n, vector<ll>(n));
        REP(j, n) if(s[j]==0 && u2[j]==1) REP(k, n) used[j][k] = 1;
        REP(j, n) if(t[j]==0 && v2[j]==1) REP(k, n) used[k][j] = 1;
        REP(j, n) REP(k, n) if(u2[j] == v2[k]) used[j][k] = u2[j];

        // 論理和が1の行の制約を満たせるように
        {
            vector<ll> zeros(n);
            REP(j, n) REP(k, n) zeros[k] += (used[j][k]==0);
            REP(j, n) if(s[j]==1 && u2[j]==1) {
                bool exist = false;
                REP(k, n) if(used[j][k]==1) exist = true;
                if(exist) continue;
                REP(k, n) if(t[k]==0 && v2[k]==0 && zeros[k]>=2) {
                    zeros[k]--;
                    used[j][k] = 1;
                    break;
                }
            }
        }
        // 列の制約を満たすように
        {
            vector<ll> zeros(n);
            REP(j, n) REP(k, n) zeros[j] += (used[j][k]==0);
            REP(j, n) if(t[j]==1 && v2[j]==1) {
                bool exist = false;
                REP(k, n) if(used[k][j]==1) exist = true;
                if(exist) continue;
                REP(k, n) if(s[k]==0 && u2[k]==0 && zeros[k]>=2) {
                    zeros[k]--;
                    used[k][j] = 1;
                    break;
                }
            }
        }
        
        REP(j, n) REP(k, n) ans[j][k] |= used[j][k]<<i;
    }

    auto check = [&] {
        REP(i, n) { 
            ll and1 = ans[i][0], or1 = 0, and2 = ans[0][i], or2 = 0;
            REP(j, n) {
                and1 &= ans[i][j];
                or1  |= ans[i][j];
                and2 &= ans[j][i];
                or2  |= ans[j][i];
            }
            if(s[i]==0 && u[i]!=and1) return false;
            if(s[i]==1 && u[i]!=or1) return false;
            if(t[i]==0 && v[i]!=and2) return false;
            if(t[i]==1 && v[i]!=or2) return false;
        }
        return true;
    };
    if(!check()) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, n) REP(j, n) cout << ans[i][j] << (j==n-1?'\n':' ');

    return 0;
}