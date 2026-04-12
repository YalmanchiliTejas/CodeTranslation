#include <bits/stdc++.h>
#define pb push_back
#define sc second
#define fr first
#define mk make_pair
#define ll long long
#define ii pair<intt,intt>
#define mp make_pair
#define scn(x) scanf("%d",&x)
typedef long long intt;
using namespace std;
intt tree[200004*4];
intt lazy[200004*4];
vector<ii> op[200004];
intt dp[200004];
void updateRange(int node,int start,int endd,int l,int r,intt val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(start!=endd)
        lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
        lazy[node] = 0;
    }
    if(start>endd||start>r||endd<l)
        return;
    if(start>=l&&endd<=r)
    {
        tree[node]+=val;
        if(start!=endd)
        lazy[node*2]+=val,lazy[node*2+1]+=val;
        return;
    }
    int mid=(start+endd)/2;
    updateRange(node*2,start,mid,l,r,val);
    updateRange(node*2+1,mid+1,endd,l,r,val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
intt queryRange(int node,int start,int endd,int l,int r)
{
    if(start>endd||start>r||endd<l)
        return -1e18;
    if(lazy[node] != 0)
    {
        tree[node]+=lazy[node];
        if(start!=endd)
        lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
        lazy[node] = 0;
    }
    if(start>=l&&endd<=r)
     return tree[node];
    int mid=(start+endd)/2;
    intt p1 = queryRange(node*2,start,mid,l,r);
    intt p2 = queryRange(node*2+1,mid+1,endd,l,r);
    return max(p1,p2);
}
int main()
{

    int n,m;

    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        op[y].pb(mk(x,z));
    }
    intt mx=0;
    for(i=1;i<=n;i++)
    {
        int j;
        intt t=queryRange(1,0,n,1,i-1);
        if(t>0)
         updateRange(1,0,n,i,i,t);
        for(j=0;j<op[i].size();j++)
          updateRange(1,0,n,op[i][j].fr,i,op[i][j].sc);
    }
    for(i=1;i<=n;i++)
     mx=max(mx,queryRange(1,0,n,i,i));
    cout<<mx<<endl;
    return 0;
}
