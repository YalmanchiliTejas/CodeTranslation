#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> G(10, vector<bool>(10, false));
    rep (i, 10) {
        G[i][0] = true;
        G[0][i] = true;
    }

    vector<int> v(N+1);
    rep (i, N+1) {
        v[i] = i;
    }

    v.erase(v.begin());

    rep (i, M) {
        ll a, b;
        cin >> a >> b;
        G[a][b] = true;        
        G[b][a] = true; // undirected graph
    }

    ll ans = 0;
    do {
        if (v[0] == 1) {
            bool tmp = true;
            for (int i = 0; i < N-1; i++) {
                tmp *= G[v[i]][v[i+1]];
            }
            if (tmp) {
                ans++;
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}