//Contains functions for implementing a disjoint set union
#include<bits/stdc++.h>
using namespace std;
//#define num 1000000007
#define num 998244353
#define inf 1000000000000000000ll
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define inarr(i,a,n,A) for(ll i=a;i<n;i++) { cin>>A[i]; }
#define vll vector<long long>
#define pi pair <int,int>
#define pll pair<long long, long long>
#define vpii vector< pair <int,int>>
#define vpll vector< pair<long long, long long>>
#define max(a,b) (a>b)?a:b
//#define min(a,b) (a>b)?b:a
#define max3(a,b,c) (a>b)?(a>c)?a:c:(b>c)?b:c
#define min3(a,b,c) (a<b)?(a<c)?a:c:(b<c)?b:c
#define avg(a,b) ((a)+(b))/2
//#define push push_back
//#define pop pop_back
#define mp make_pair
#define sf int flag=0     //Remember semicolon
#define assmin(a,b) if(b<=a) { a=b; }
#define assmax(a,b) if(b>=a) { a=b; }
#define fir first
#define sec second
#define mod(a) ((a)>0)?(a):(-(a))
 
 
typedef long long ll;
 
ll next(ll a, ll n)
{
    return (a==n-1)?0:a+1;
}
ll parent[1000005],size[1000005],  tail[300005];
set<ll> cur_par;
ll n,m,q;
ll pos(ll x,ll y)
{
    return (m*(x-1))+y;
}
void init_parent(ll n)
{
    memset(parent,-1,sizeof(parent[0])*n);
}
void make_set(ll v)
{
    parent[v]=v;
    ::size[v]=1;
    tail[v]=v;
}
ll find_set(ll v)
{
    if(parent[v]==v)
    return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(ll a,ll b, ll A[])
{
    a=find_set(a);
    b=find_set(b);
    if(a==b)
    return;
    if(::size[a]<::size[b])
    {
        swap(a,b);
    }
    parent[b]=a;
    ::size[a]+=::size[b];
    A[a] = min(A[a], A[b]);
}
ll prev(ll a,ll n)
{
    if(a==0)
    return n-1;
    return a-1;
}
ll nex(ll a,ll n)
{
    if(a==n-1)
    return 0;
    else
    return a+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll A[n+1];
    REP(i,1,n+1)
    {
        cin>>A[i];
    }
    ll dpfloor[n+1], dpceil[n+1];
    dpfloor[1] = 0;
    dpceil[1] = A[1];
    dpfloor[2] = dpceil[2] = max(A[1], A[2]);
    REP(i,3,n+1)
    {
        if(i&1)
        {
            dpfloor[i] = max(dpfloor[i-1], dpfloor[i-2]+A[i]);
            dpceil[i] = dpceil[i-2] + A[i];
        }
        else
        {
            dpfloor[i] = dpceil[i] = max(dpceil[i-1], dpfloor[i-2]+A[i]);
        }
    }
    cout<<dpfloor[n]<<endl;
    return 0;
}
