#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;


int main(){
    int n, m;
    int ans = 0;
    cin >> n >> m;
    vector<int> edge[n];
    vector<int> junretu(n-1);
    REP(i, n-1) {
        junretu[i] = i+1;
    }
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    do {
        int now = 0;
        bool seikou = true, seikou2 = false;
        REP(i, n-1) {
            seikou2 = false;
            REP(j, edge[now].size()) {
                if(edge[now][j] == junretu[i]) seikou2 = true;
            }
            if(!seikou2) {
                seikou = false;
                break;
            }
            now = junretu[i];
        }
        if(seikou) ans++;
    } while (next_permutation(junretu.begin(), junretu.end()));

    cout << ans << endl;

    return 0;
}
