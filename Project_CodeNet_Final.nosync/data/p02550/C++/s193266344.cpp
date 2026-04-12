#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#pragma GCC optimize(2)
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define l first
#define r second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=100010;
ll n,x,m;
int st[N];
ll s[N];
int main()
{
    IO;
    int T=1;
    //cin>>T;
    while(T--)
    {
        cin>>n>>x>>m;
        ll l,r;
        for(ll a=x,k=1;;a=a*a%m,k++)
        {
            if(!st[a]) st[a]=k;
            else
            {
                l=st[a],r=k-1;
                break;
            }
            s[k]=s[k-1]+a;
        }
        ll len=r-l+1;
        ll res=0;
        res+=s[min(n,l-1)];
        n=max(0ll,n-l+1);
        if(n) res+=(s[r]-s[l-1])*(n/len)+(s[n%len+l-1]-s[l-1]);
        cout<<res<<'\n';
    }
    return 0;
}