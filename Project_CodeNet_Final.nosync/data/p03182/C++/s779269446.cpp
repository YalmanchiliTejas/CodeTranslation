#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int N = 2e5+10;
 
int seg[4*N];
int lazy[4*N];
 
void push(int ss,int se,int node)
{
    seg[node]+=lazy[node];
    
    if(ss != se)
    {
        lazy[node*2+1]+=lazy[node];
        lazy[node*2+2]+=lazy[node];
    }
    
    lazy[node] = 0;
}
 
void update(int node,int ss,int se,int l,int r,int x)
{
    push(ss,se,node);
    
    if(ss > r || se < l) return;
    
    if(l <= ss && se <= r)
    {
        lazy[node]+=x;
        push(ss,se,node);
        return;
    }
    
    int mid = (ss+se)/2;
    
    update(node*2+1,ss,mid,l,r,x);
    update(node*2+2,mid+1,se,l,r,x);
    
    seg[node] = max(seg[node*2+1],seg[node*2+2]);        
}
 
int query(int node,int ss,int se,int id)
{
    push(node,ss,se);
    
    if(se < id || ss > id) return 0;
    
    if(ss == id && se == id) return seg[node];
    
    int mid = ( ss + se)/2;
    
    return query(node*2+1,ss,mid,id) + query(node*2+2,mid+1,se,id);
}
 
pair<pii,int> a[N];
int adder[N];
int dp[N];
int n,m;
 
signed main()
{
    fast;
    
    cin >> n >> m;
    
    f(i,m) cin >> a[i].F.F >> a[i].F.S >> a[i].S;
    
    f(i,m)
    {
         adder[a[i].F.F]+=a[i].S;
         adder[a[i].F.S+1]-=a[i].S;
    }
    
    f(i,m) swap(a[i].F.F,a[i].F.S);
    sort(a,a+m);
    f(i,m) swap(a[i].F.F,a[i].F.S);
    
    int id = 0;
    
    for(int i=1;i<=n;i++)
    {
        adder[i]+=adder[i-1];
        
        dp[i] = seg[0] + adder[i];
        
        update(0,0,n-1,i,i,dp[i]  - adder[i]);
        
        while(id < m && a[id].F.S <= i)
        {
            update(0,0,n-1,a[id].F.F,a[id].F.S,a[id].S);
            id++;
        }
    }
    
    int res = 0;
    
    for(int i=1;i<=n;i++) res = max(res,dp[i]);
    
    cout << res;
}