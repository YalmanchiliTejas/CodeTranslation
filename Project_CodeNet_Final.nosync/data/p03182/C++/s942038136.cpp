#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;

typedef long long ll;

ll tree[4 * maxn];
ll lazy[4 * maxn];

void push(int node, int l, int r)
{
    if(lazy[node] == 0)
        return;
    tree[node] += lazy[node];
    if(l != r)
    {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int x, int y, ll val)
{
    //cout << node << " " << l << " -- " << r << endl;
    push(node,l,r);
    if(l > r || l > y || r < x)
        return;
    if(x <= l && r <= y)
    {
        lazy[node] += val;
        push(node,l,r);
        return;
    }

    int mid = (l+r) >> 1;
    update(2*node,l,mid,x,y,val);
    update(2*node+1,mid+1,r,x,y,val);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

ll query(int node, int l, int r, int x, int y)
{
    push(node,l,r);
    if(l > r || l > y || r < x)
        return -(1LL << 60);
    if(x <= l && r <= y)
    {
        return tree[node];
    }

    int mid = (l+r) >> 1;
    return max(query(2*node,l,mid,x,y),query(2*node+1,mid+1,r,x,y));
}

vector<pair<int,int> >que[maxn];

int main()
{
    // for(int i = 0; i < 4*maxn; i++)
    //     tree[i] = -(1LL << 60);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m ; i++)
    {
        int l,r,d;
        scanf("%d %d %d",&l,&r,&d);
        que[r].push_back({l,d});
    }

    for(int i = 1 ; i <= n; i++)
    {   
        ll q = query(1,1,n,1,i);
        update(1,1,n,i,i,q);
        for(auto &x : que[i])
        {
            update(1,1,n,x.first,i,x.second);    
        }
    }
    printf("%lld\n",max(0LL,query(1,1,n,1,n)));
    return 0;
}