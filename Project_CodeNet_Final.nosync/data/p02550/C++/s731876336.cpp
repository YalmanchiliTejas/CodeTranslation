#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
ll a[100005],sum[100005];
int main(){
    ll n,x,m;cin>>n>>x>>m;
    ll now=x,num=1;
    while(!a[now]){
        a[now]=num;sum[num]=sum[num-1]+now;
        num++;now=now*now%m;
    }
    ll l=a[now],r=num-1;
    if(n<=r){
        cout<<sum[n]<<endl;return 0;
    }
    n-=r;ll ans=sum[r],v=n%(r-l+1);
    cout<<ans+(n/(r-l+1))*(sum[r]-sum[l-1])+(sum[l+v-1]-sum[l-1])<<endl;
}