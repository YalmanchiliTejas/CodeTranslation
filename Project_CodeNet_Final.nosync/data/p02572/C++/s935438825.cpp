#include <iostream>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    long long int arr[n+1],sum[n+1],prod=1,ans=0;
    sum[n]=0;
     for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]= arr[i]%mod;
    }
    for(int i=n-1;i>0;i--)
    {
       sum[i]=arr[i]+sum[i+1];
       sum[i]%=1000000007;
     }
   // cout<<total<<endl;
    for(int i=0;i<n-1;i++)
    {
           prod = (arr[i]*sum[i+1])%mod;
           prod = prod%mod;
           ans = ans + prod;
           ans = ans%mod;
    }
    cout<<ans<<endl;
    return 0;
}
