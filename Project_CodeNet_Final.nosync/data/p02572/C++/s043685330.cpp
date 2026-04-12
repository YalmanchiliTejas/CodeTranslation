#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005],sum=0,s=0;
const int mod=1000000007;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        {
            cin>>a[i];
            s+=a[i];
            s%=mod;
            b[i+1]=s;
        }
    b[0]=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i]*b[i]%mod;
        sum%=mod;
    }
    cout<<sum;
    return 0;
}
