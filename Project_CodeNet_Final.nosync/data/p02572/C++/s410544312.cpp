#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
long long int tree[4*N]={0};
#define ff first
#define ss second
void update(long int node,long int l,long int r,long int ind,long long int val)
{
    if(l==r)
    {
        tree[node] = val;
    }
    else
    {
        long int mid = (l+r)/2;
        if(mid>=ind)
         update(2*node+1,l,mid,ind,val);
         else
         update(2*node+2,mid+1,r,ind,val);
         tree[node] = max(tree[2*node+1],tree[2*node+2]);
    }
}
long long int query(long int node,long int l,long int r,long int L,long int R)
{
    if(L>r || l>R)
    return 0;
    if(L<=l && R>=r)
    return tree[node];
    long int mid = (l+r)/2;
    return max(query(2*node+1,l,mid,L,R),query(2*node+2,mid+1,r,L,R));
}
long long int mod = 1e9+7;
bool compare(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
    return a.ff>b.ff;
}

long long int power(long long int x,long long int y)
{
    long long int res=1;
    while(y>0)
    {
        if(y&1)res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    long int t=1;
    // cin>>t;
    long int kk=0;
    while(t--)
    {
        long int n;
        cin>>n;
       long long int a[n],aa=0,bb=0;
       for(long int i=0;i<n;i++)
       {
           cin>>a[i];
           aa+=a[i];
           aa%=mod;
       }
       aa=(aa*aa)%mod;
       for(long int i=0;i<n;i++)
       {
           aa-=(a[i]*a[i]);
           aa%=mod;
           aa+=mod;
       }
       aa=(aa*power(2,mod-2))%mod;
       cout<<aa;
    }
}