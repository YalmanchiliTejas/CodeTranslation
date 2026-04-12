#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

const int len = 2e5+5;
const ll inf = 1e16;
ll tree[4*len], dp[len], lazy[4*len];
vector<ii> vec[len];

void prop(int p, int l, int r){
    if (lazy[p] == 0)
        return;

    tree[p] += lazy[p];
    if (l < r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int i, int j, ll v){
    prop(p, l, r);
    if (r < i || j < l)
        return;
    if (i <= l && r <= j)
        lazy[p] += v;
    else{
        int mid = (l+r)/2;
        update(2*p, l, mid, i, j, v), update(2*p+1, mid+1, r, i, j, v);
        prop(2*p, l, mid), prop(2*p+1, mid+1, r);
        tree[p] = max(tree[2*p], tree[2*p+1]);
    }
}

ll query(int p, int l, int r, int i, int j){
    prop(p, l, r);
    if (r < i || j < l)
        return -inf;
    if (i <= l && r <= j)
        return tree[p];

    int mid = (l+r)/2;
    return max(query(2*p, l, mid, i, j), query(2*p+1, mid+1, r, i, j));
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        vec[l].pb(mp(r, c));
    }

    for (int i = n; i >= 0; i--){
        dp[i] = max(0LL, query(1, 1, n, i+1, n));

        if (i == 0)
            break;

        update(1, 1, n, i, i, dp[i]);
        for (int j = 0; j < vec[i].size(); j++){
            ii v = vec[i][j];
            update(1, 1, n, i, v.fi, v.se);
        }
    }

    printf("%lld\n", dp[0]);
    return 0;
}
