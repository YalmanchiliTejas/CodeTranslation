#include<bits/stdc++.h>
using namespace std;
 long long mod =1000000007;
int main()
{

    long long int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<long long int> suff(n);
    suff[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suff[i]=(arr[i]+suff[i+1])%mod;
    }
    long long int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans+=(arr[i]*suff[i+1])%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
