#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX=100005;

vector <ll> a;
bool vis[MX];
int pos[MX];

ll f(int p,ll n)
{
    ll x=0,sum=0;
    ll l=a.size();
    for(int i=p;(i<l && n);i++,n--) x+=a[i];
    if(n==0) return x;
    ll k=n/(l-p),r=n%(l-p);
    for(int i=p;i-p<r;i++) x+=a[i];
    for(int i=p;i<l;i++) sum+=a[i];
    return x+sum*k;
}

int main()
{
    ll n,x,m,ans=0;
    cin>> n >> x >> m;
    for(int i=0;i<n;i++){
        if(vis[x]){
            ans+=f(pos[x],n-i);
            break;
        }
        pos[x]=i;
        vis[x]=true;
        a.push_back(x);
        ans+=x;
        x=(x*x)%m;
    }
    cout<< ans <<endl;
    return 0;
}