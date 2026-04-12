#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second

int ans=0;
vector<pair<int,int>> strt[200005];
vector<pair<int,int>> fin[200005];
int n,m1;

struct stnode
{
    int ma;
};
stnode st[800005];
int  lazy[800005]={0};
void merge(stnode &f,stnode &n1,stnode &n2)
{
    f.ma=max(n1.ma , n2.ma);
}
void build(int node ,int l ,int r)
{
    lazy[node]=0;
    if(l==r)
    {
        st[node].ma=0;
        return ; 
    }
    int m=(l+r)/2;
    build(2*node , l, m);
    build(2*node + 1, m+1 ,r);
    merge(st[node],st[2*node],st[2*node +1]);
}
void propogate(int node,int l,int r)
{
    st[node].ma+=lazy[node];
    //cout<<node<<" "<<st[node].ma<<"\n";
    if(l!=r)
    {
        lazy[node*2]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
}
void update(int node,int l,int r,int tl,int tr,int val)
{
    //lazy[node]+=val;
    //cout<<node<<" "<<l<<" "<<r<<" "<<tl<<" "<<tr<<" "<<val<<"\n";
    if(lazy[node]!=0)
        propogate(node,l,r);
    if(r<tl || l>tr)
        return;
    if(l>=tl && r<=tr)
    {
        lazy[node]+=val;
        propogate(node,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(2*node,l,mid,tl,tr,val);
    update(2*node+1,mid+1,r,tl,tr,val);
    merge(st[node],st[2*node],st[2*node +1]);
}
stnode query(int node, int L, int R, int i, int j)
    {
        //cout<<node<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<"\n";
        if(lazy[node]!=0)
            propogate(node, L, R);
        if(j<L || i>R)
        {
            //cout<<node<<" jhc\n";
            return stnode();
        }
        if(i<=L && R<=j)
        {
            //cout<<node<<" "<<st[node].ma<<"\n";
            return st[node];
        }
        int M = (L + R)/2;
        if(j<=M)
            return query(node*2 , L, M, i, j);
        if(i>M)
            return query(node*2 +1, L, M, i, j);

        stnode left=query(node*2, L, M, i, j);
        stnode right=query(node*2 + 1, M + 1, R, i, j);
        stnode cur;
        merge(cur, left, right);
        return cur;
    }
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m1;
    for(int i=0;i<m1;i++)
    {
        int l,r,val;
        cin>>l>>r>>val;
        strt[l].push_back({r,val});
        fin[r].push_back({l,val});
    }
    int cursum=0;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" ";
        int dp=0;
        for(auto &k:strt[i])
            cursum+=k.second;
        //cout<<cursum<<" ";
        dp=query(1,1,n,1,i).ma;
        ans=max(ans,dp + cursum);
        update(1,1,n,i,i,dp + cursum);
        //cout<<query(1,1,n,1,1).ma<<" ";
        for(auto &k:fin[i])
        {
            cursum-=k.second;
            update(1,1,n,k.first,i-1,k.second);
        }
        update(1,1,n,i,i,-cursum);
        //cout<<ans<<"\n";
        //cout<<i<<"\n";
    }
    cout<<ans;

} 