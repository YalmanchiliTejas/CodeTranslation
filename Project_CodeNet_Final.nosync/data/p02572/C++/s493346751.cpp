#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mm(a,x) memset(a,x,sizeof(a))
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0)
#define ll long long
using namespace std;
const int N=2e5+10;
const ll mod=1e9+7;
int a[N];
ll pre[N];
int main(void)
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pre[i]=(pre[i-1]+a[i])%mod;
    }
    ll res=0;
    for(int i=1;i<=n;++i)
        res=(res+a[i]*(pre[n]-pre[i]+mod)%mod)%mod;
    cout<<res<<endl;
    return 0;
}