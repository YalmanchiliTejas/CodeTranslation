#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

const int N=2e5+10,mod=1e9+7;;

LL a[N],s[N];

int main()
{
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=(s[i-1]+a[i])%mod;
    }
    for(int i=1;i<n;i++) sum=(sum+(a[i]*(((s[n]-s[i])%mod+mod))%mod))%mod;
    cout<< sum <<endl;
    return 0;
}