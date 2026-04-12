#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define repll(i,n) for(ll i=0;i<(ll)(n);i++)
#define repll2(i,n) for(ll i=1;i<=(ll)(n);i++)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define INF (int)1e9
#define LINF (ll)4e18
#define MOD (ll)(1e9)+7
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PI 3.1415926535898
#define NP(v) next_permutation(v.begin(),v.end())

//------------------------------------------------------

set<int> edge[10];

int main() {
    int n, m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        edge[a].insert(b);
        edge[b].insert(a);
    }

    vector<int> p;

    REP(i, 2, n + 1) {
        p.push_back(i);
    }

    int ans = 0;

    do {
        bool can = true;

        if (!edge[1].count(p[0])) can = false;

        rep(i, n - 2) {
            if (!edge[p[i]].count(p[i + 1])) {
                can = false;
                break;
            }
        }

        if (can) ans++;
    } while (NP(p));

    cout << ans << endl;

    return 0;
}