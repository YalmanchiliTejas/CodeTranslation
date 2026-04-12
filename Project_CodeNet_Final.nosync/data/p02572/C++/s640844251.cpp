#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   t=1;
   int mod=1e9+7;
   while(t--)
   {
    int n;
    cin>>n;
    ll a[n];
    ll prefix[n]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    prefix[1]=a[0];
    for(int i=2;i<n;i++)
        prefix[i]+=(prefix[i-1]+a[i-1]);
    ll sum=0;
    for(int i=1;i<n;i++)
         sum=((sum%mod)+((prefix[i]%mod)*(a[i]%mod))%mod)%mod;
    cout<<sum;
   }
}
