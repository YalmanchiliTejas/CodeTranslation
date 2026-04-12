#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
ll M=1e9+7;
//string s,p;
//vector<int>v;
//map<int,int>mp;
ll a[N],d[N];
int main()
{
    ft
    ll t,i,j,n,m,k,l,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=a[i];
    }
    for(i=1;i<=n;i++)
    {
        d[i]+=d[i-1];
    }
    ll s=0;
    for(i=1;i<n;i++)
    {
        a[i]%=M;
        s+=a[i]*((d[n]-d[i])%M);
        s%=M;
    }
    cout<<s<<"\n";
    return 0;
}

