#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll cycling(long long K, int state_size, int s, std::function<int(int)> trans){
    vector<int> seq, vis;
    vis.assign(state_size + 1, -1);
    seq.push_back(s);
    vis[s] = 0;
    int l = 0, r = 0;
    // seq[l] = seq[r]
    while(r < K){
        s = trans(s);
        seq.push_back(s);
        r++;
        if(vis[s] != -1){
            l = vis[s];
            break;
        }
        vis[s] = r;
    }
    ll ret = 0;
    FOR(i, l, r) ret += seq[i];
    ret *= (K - l) / (r - l);
    REP(i, (K - l) % (r - l)) ret += seq[l + i];
    REP(i, l) ret += seq[i];
    return ret;
}

ll N, X, M;

signed main(){
    cin >> N >> X >> M;
    ll ans = cycling(N, M, X, [&](ll x) -> ll{return x * x % M;});
    PRINT(ans);
    return 0;
}