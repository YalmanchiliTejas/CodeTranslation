#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans=0,suffixSum=0, m=1000000007;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        ans = ans+(suffixSum*a[i]);
        suffixSum = suffixSum + a[i];
        ans = ans%m;
        suffixSum = suffixSum%m;
    }
    cout<<ans<<endl;

    return 0;
}
