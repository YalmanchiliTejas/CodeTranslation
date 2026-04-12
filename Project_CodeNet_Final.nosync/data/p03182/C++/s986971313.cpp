#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const ll inf = 1e18 + 1;
const double eps = 1e-9;
const int MAXN = 2e5 + 5;
const int offset = 1<<18;

int n, m;
int l[MAXN], r[MAXN];
ll c[MAXN];
ll T[4*offset], prop[4*offset];
ll dp[MAXN];
ll sol;
vector <pii> vpii;
vector <vector<pii> > v;

void build(){
    for (int i = 0; i < 4*offset; i++) T[i] = prop[i] = 0;
    return;
}

void refresh(int cvor){
    T[cvor*2] += prop[cvor];
    prop[cvor*2] += prop[cvor];
    T[cvor*2+1] += prop[cvor];
    prop[cvor*2+1] += prop[cvor];
    prop[cvor] = 0;
}

void update(int cvor, int l, int r, int a, int b, ll x){
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        T[cvor] += x;
        prop[cvor] += x;
        return;
    }

    refresh(cvor);

    int mid = (l+r)/2;

    update(cvor*2, l, mid, a, b, x);
    update(cvor*2+1, mid+1, r, a, b, x);

    T[cvor] = max(T[cvor*2], T[cvor*2+1]);
}

ll query(int cvor, int l, int r, int a, int b){
    if (l > b || r < a) return -inf;
    if (l >= a && r <= b) return T[cvor];

    refresh(cvor);

    int mid = (l+r)/2;

    ll x = query(cvor*2, l, mid, a, b);
    ll y = query(cvor*2+1, mid+1, r, a, b);

    return max(x, y);
}

int main(){

    build();

    cin >> n >> m;
    v.insert(v.begin(), n, vpii);
    for (int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> c[i];
        l[i]--; r[i]--;
        v[r[i]].pb(mp(l[i], c[i]));
        update(1, 0, offset-1, l[i], offset-1, -c[i]);
    }

    for (int i = 0; i < n; i++){
        dp[i] = -query(1, 0, offset-1, i, i);
        dp[i] = max(dp[i], dp[i]+query(1, 0, offset-1, 0, i-1));
        update(1, 0, offset-1, i, i, dp[i]);
        for (int j = 0; j < v[i].size(); j++) update(1, 0, offset-1, v[i][j].fi, offset-1, v[i][j].se);
        sol = max(sol, dp[i]);
    }

    cout << sol;

    return 0;

}
