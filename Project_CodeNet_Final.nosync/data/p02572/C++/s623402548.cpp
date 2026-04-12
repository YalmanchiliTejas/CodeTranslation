#include <iostream>
#include <cstring>
using namespace std;
const int mod=1e9+7;
long long n,ans,pre;
long long a[210000];
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    pre=a[0];
    for(int i=1;i<n;i++)
    {
        ans%=mod;
        ans=(ans+pre*a[i]%mod)%mod;
        pre=(pre+a[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
