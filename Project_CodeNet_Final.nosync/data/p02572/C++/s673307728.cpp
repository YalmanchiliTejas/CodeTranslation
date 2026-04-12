#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t,n;
    t = 1;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        ll sum[n];
        for(int i=0;i<n;i++)
        {
            sum[i] = 0;
            cin>>arr[i];
        }
        for(int i= n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                sum[i] = arr[i];
            }
            else
            {
                sum[i] = (sum[i+1]+arr[i])%mod;
            }
        }
        ll ans = 0;
        for(int i=0;i<n-1;i++)
        {
            ans = (ans+(arr[i]*sum[i+1])%mod)%mod;
        }
        cout<<ans;
    }
    return 0;
}