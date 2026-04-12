#include <bits/stdc++.h>

using namespace std;

#define MAX 200005
#define ll long long
ll tree[4*MAX], prop[4*MAX];
vector<pair<ll, ll> > V[MAX];

void propagate(int node, int b, int e)
{
    if(prop[node] == 0) return;
    tree[node] += prop[node];
    if(b != e){
        prop[2*node] += prop[node];
        prop[2*node+1] += prop[node];
    }
    prop[node] = 0;
}

void update(int node, int b, int e, int l, int r, ll val)
{
    propagate(node, b, e);
    if(l > e || r < b) return;
    if(b >= l && e <= r){
        prop[node] += val;
        propagate(node, b, e);
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    update(left, b, mid, l, r, val);
    update(right, mid+1, e, l, r, val);
    tree[node] = max(tree[left], tree[right]);
}

ll query(int node, int b, int e, int l, int r)
{
    propagate(node, b, e);
    if(l > r || l > e || r < b) return 0;
    if(b >= l && e <= r){
        return tree[node];
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    ll q1 = query(left, b, mid, l, r);
    ll q2 = query(right, mid+1, e, l, r);
    return max(q1, q2);
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    memset(tree, 0, sizeof tree);
    memset(prop, 0, sizeof prop);
    for(int i=0; i<m; i++){
        int l, r, val;
        scanf("%d %d %d", &l, &r, &val);
        V[r].push_back(make_pair(l, val));
    }
    for(int i=1; i<=n; i++){
        ll q = query(1, 0, n, 0, i-1);
        q = max(0LL, q);
        update(1, 0, n, i, i, q);
        for(int j=0; j<V[i].size(); j++){
            ll l = V[i][j].first;
            ll val = V[i][j].second;
            update(1, 0, n, l, i, val);
        }
    }
    cout << max(0LL, query(1, 0, n, 0, n));
}
