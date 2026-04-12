#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+5;
int sum[maxm];
int d[maxm];//d[i]为前i个数取i/2个的最大值
int a[maxm];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i&1)sum[i]=sum[i-1]+a[i];
        else sum[i]=sum[i-1];
    }
    for(int i=2;i<=n;i++){
        if(i&1)d[i]=max(d[i-2]+a[i],d[i-1]);
        else d[i]=max(d[i-2]+a[i],sum[i-1]);
    }
    cout<<d[n]<<endl;
    return 0;
}
