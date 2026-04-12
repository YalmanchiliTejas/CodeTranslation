#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<int> ord(N);
    rep(i, N) ord[i] = i;
    int res = 0;
    do {
        if(ord[0] != 0)
            continue;
        for(int i = 0; i < N - 1; i++) {
            int ok = 0;
            for(auto x : G[ord[i]]) {
                if(x == ord[i + 1])
                    ok = 1;
            }
            if(!ok)
                break;
            if(ok && i == N - 2)
                res++;
        }
    } while(next_permutation(All(ord)));
    cout << res << endl;
    return 0;
}