#include<iostream>
#include<cstring>
using namespace std;
int mod=1000000007;
int main()
{
    int n;
    int a[200010];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long sum[200010];
    memset(sum,0,sizeof(sum));
    for(int i=n;i>=1;i--)
        sum[i]=a[i]+sum[i+1]%mod;
    long long ans=0;
    for(int i=1;i<n;i++)
        ans=(ans+a[i]*sum[i+1]%mod)%mod;
    cout<<ans<<endl;
    return 0;
}