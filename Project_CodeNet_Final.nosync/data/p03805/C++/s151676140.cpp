#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

int dfs(vector<vector<ll> >& e, int node, vector<int> visited, int depth) {
    visited[node] = 1;
    if (depth == e.size() - 1) {
        return 1;
    }

    auto& c = e[node];
    int sum = 0;
    rep(i, c.size()) {
        if (visited[c[i]] <= 0) {
            sum += dfs(e, c[i], visited, depth + 1);
        }
    }

    return sum;
}

void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    
    vector<vector<ll> > e(n + 1, vector<ll>());
    rep(i, m) {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }

    vector<int> visited(n + 1);
    put(dfs(e, 1, visited, 1));
}
signed main(){ Main();return 0;}