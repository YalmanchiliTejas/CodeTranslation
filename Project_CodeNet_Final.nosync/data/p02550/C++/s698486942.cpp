#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll N,X,M; cin >> N >> X >> M;
    vector<pair<ll,ll>> vm(M+1,make_pair(-1,1));
    vector<ll> memo(M+1,-1);
    vm[X] = make_pair(X,1);
    ll now = X;
    ll sum = X;
    memo[1] = X;
    memo[0] = 0;
    if (X == 0) {
        cout << 0 << endl;
        return;
    }
    // 回目
    FOR(cnt,2,min(M+1,N+1)) {
        now = (now*now) % M;
        if (now < 0) now+=M;

        if (now == 0) {
            cout << sum << endl;
            return;
        } else if (vm[now].first == -1) {
            sum += now;
            vm[now] = make_pair(sum,cnt);
            memo[cnt] = sum;
        } else {
            // cycle is cnt+1
            ll cycle_size = cnt - vm[now].second;
            ll cycle_point = memo[cnt-1] - memo[vm[now].second-1];
            // 残りのサイクル可能数
            ll can_cycle = (N-cnt+1) / cycle_size;
            // サイクル可能数だけ追加
            sum += cycle_point * can_cycle;
            // 余り
            ll surplus = (N-cnt+1) % cycle_size;
            // 余剰分の計算
            if (surplus > 0 )sum += now;
            REP(i,surplus-1) {
                now = (now*now) %M;
                sum += now;
            }
            cout << sum << endl;
            return;
        }
    }
    cout << sum << endl;
}

int main() {
    solve();
    return 0;
}