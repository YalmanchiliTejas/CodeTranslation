#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<pii> vpii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
    tree_order_statistics_node_update> ost;

const int N=110000;
vi adj[N];
int m[N], mr[N];

void dfs(int x, int p) {
    mr[x]=1;
    for(int y: adj[x]) if(y!=p) {
        dfs(y, x);
        m[x]=(mr[x]&&mr[y]) || (m[x]&&m[y]);
        mr[x]=mr[x]&&m[y];
    }
}

int main() {
    int i, n, u, v;
    scanf("%d", &n);
    for(i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    printf(m[1]? "Second\n" : "First\n");
    return 0;
}