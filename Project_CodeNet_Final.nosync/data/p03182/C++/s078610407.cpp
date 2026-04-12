//https://atcoder.jp/contests/dp/tasks/dp_w
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const ll inf=2e5+9,MX=1e18+9;
ll l[inf],r[inf],val[inf],n,m,dp[inf],ans,tree[inf<<2],lazy[inf<<2],vis[inf<<2];
vector<ll> add[inf],del[inf];

void lazyupdate(ll node,ll l,ll r){

    if(lazy[node]==0)
        return ;

    vis[node]=1;
    tree[node]+=lazy[node];

    if(l!=r)
        lazy[le]+=lazy[node],lazy[ri]+=lazy[node];

    lazy[node]=0;

}

void update(ll node,ll l,ll r,ll x,ll y,ll val){

    lazyupdate(node,l,r);

    if(l>r || r<x || l>y)
        return ;

    vis[node]=1;

    if(l>=x && r<=y){
        lazy[node]+=val;
        lazyupdate(node,l,r);
        return ;
    }

    update(le,l,mid,x,y,val);
    update(ri,mid+1,r,x,y,val);
    tree[node]=max( (vis[le]?tree[le]:-MX), (vis[ri]?tree[ri]:-MX));
}

ll query(ll node,ll l,ll r,ll x,ll y){

    lazyupdate(node,l,r);

    if(l>r || r<x || l>y )
        return -MX;

    if(l>=x && r<=y)
        return tree[node];

    ll ret= max(query(le,l,mid,x,y),query(ri,mid+1,r,x,y));
    tree[node]=max( (vis[le]?tree[le]:-MX), (vis[ri]?tree[ri]:-MX));
    return ret;
}

int main(){

    cin>>n>>m;
    for(ll i=1;i<=m;i++)
        cin>>l[i]>>r[i]>>val[i],add[l[i]].push_back(i),del[r[i]].push_back(i);

    for(ll i=1;i<=n;i++){

        for(auto o:add[i])
            update(1,0,n,0,l[o]-1,val[o]);

        dp[i]=query(1,0,n,0,i-1);

        ans=max(ans,dp[i]);

        update(1,0,n,i,i,dp[i]);

        for(auto o:del[i])
            update(1,0,n,0,l[o]-1,-val[o]);
    }
    cout<<ans<<endl;
}
