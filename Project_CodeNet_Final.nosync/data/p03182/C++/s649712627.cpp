#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll esq[200005], dir[200005], val[200005];
ll tree[800005], lazy[800005];
vector<ii> adj[200005];

ll left(ll u){return (u << 1);}
ll right(ll u){return (u << 1) + 1;}

void push(ll u, ll L, ll R){
    if(lazy[u]) tree[u] += lazy[u];
    if(L != R){
        lazy[left(u)] += lazy[u];
        lazy[right(u)] += lazy[u];
    }
    lazy[u] = 0;
}

void update(ll u, ll L, ll R, ll i, ll j, ll x){
    push(u, L, R);
    if(R < i || L > j) return;
    if(L >= i and R <= j){
        lazy[u] += x;
        push(u, L, R);
        return;
    }
    ll mid = (L+R)/2;
    update(left(u), L, mid, i, j, x);
    update(right(u), mid+1, R, i, j, x);
    tree[u] = max(tree[left(u)], tree[right(u)]);
}

ll query(ll u, ll L, ll R, ll i, ll j){
    push(u, L, R);
    if(R < i || L > j) return -1e18;
    if(L >= i and R <= j) return tree[u];
    ll mid = (L+R)/2;
    ll r1 = query(left(u), L, mid, i, j);
    ll r2 = query(right(u), mid+1, R, i, j);
    return max(r1,r2);
}

int main(){
    ll n, m; cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> esq[i] >> dir[i] >> val[i];
        adj[dir[i]].push_back({esq[i], val[i]});
    }
    //update(1, 1, n, 1, n, -1e7);
    for(ll i = 1; i <= n; i++){
        ll x = query(1, 1, n, 1, n);
        //cout << i << " = " << x << endl;
        update(1, 1, n, i, i, x);
        //prllf("update %d %d %d %d %d %d\n", 1, 1, n, i, i, x);
        for(ii par : adj[i]){
            update(1, 1, n, par.first, i, par.second);
            //prllf("update %d %d %d %d %d %d\n", 1, 1, n, par.first, i, par.second);
        }
    }
    
    ll res = 0;
    for(int i = 1; i <= n; i++) res = max(res, query(1, 1, n, i, i));
    cout << res << endl;
    return 0;
}