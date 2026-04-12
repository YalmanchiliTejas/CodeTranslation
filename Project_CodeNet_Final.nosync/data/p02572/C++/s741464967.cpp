#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
long long a[200005];
long long sum[200005];
const int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    long long num=0;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=n;i>=1;i--)
    {sum[n-i+1]=sum[n-i]+a[i];
    sum[n-i+1]%=mod;
    }
    for (int i=1;i<n;i++)
    {
        num+=a[i]*sum[n-i]%mod;
        num%=mod;
    }
    cout<<num%mod<<endl;
    return 0;
}
