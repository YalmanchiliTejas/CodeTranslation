#include <bits/stdc++.h>
using namespace std;
int main()
{long long n=0,s=0,s1=0;
    cin>>n;
    long long a[n],a1[n];
    for(long long j=0;j<n;j++)
    {
        cin>>a[j];
        s+=a[j];
        a1[j]=s;
    }
    for(long long j=0;j<n-1;j++)
    {
        s1=((s1%(1000000007))+((((a[j]%(1000000007))*((a1[n-1]-a1[j])%1000000007))%1000000007)%1000000007))%1000000007;
        
    }
    cout<<s1;
}