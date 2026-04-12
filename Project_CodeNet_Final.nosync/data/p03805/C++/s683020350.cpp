#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N, 0));
    Rep (i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b]++;
        G[b][a]++;
    }

    vector<ll> v;
    Rep (i, N) v.push_back(i);
    ll ans = 0;
    do {
        if (v[0] != 0) continue;
        bool pos = true;
        Rep (i, N-1) {
            if (G[v[i]][v[i+1]] == 0) {
                pos = false;
                break;
            }
        }
        if (pos) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
}