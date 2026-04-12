#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+5;

ll cp[60]={1},cb[60]={0};

ll dfs(int n,ll x)
{
    if(n==0)return 1;
    ll sum=cp[n-1]+cb[n-1];
    if(x==1)return 0;
    if(x<=1+sum)return dfs(n-1,x-1);
    if(x==1+sum+1)return cp[n-1]+1;
    if(x<=1+sum+1+sum)return cp[n-1]+1+dfs(n-1,x-sum-2);
    return cp[n-1]*2+1;
}
int main()
{
    for(int i=1;i<=51;i++)
    {
        cp[i]=2*cp[i-1]+1;
        cb[i]=2*cb[i-1]+2;
    }
    ll n,x;
    while(cin>>n>>x)
    {
        ll ans=dfs(n,x);
        cout<<ans<<endl;
    }
}
