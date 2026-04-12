#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rg register
#define ll long long 
#define inf 0x3f3f3f3f
ll n,k;
ll a[55],b[55];
ll hh[6]={0,0,1,2,3,3};
ll work(ll res,ll lev)
{
    ll tmp=b[lev-1]+2;
    if(lev==0)
        return res>0;
    
    if(res<tmp) return work(res-1,lev-1);
    else if(res==tmp) return a[lev-1]+1;
    else return work(res-b[lev-1]-2,lev-1)+1+a[lev-1];
}
int main(){
    //freopen("a.in","r",stdin);
    scanf("%lld%lld",&n,&k);
    a[0]=b[0]=1;
    for(int i=1;i<=n;i++)
        a[i]=a[i-1]*2+1,b[i]=b[i-1]*2+3;
        /*
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    */
    printf("%lld\n",work(k,n));
    return 0;
}