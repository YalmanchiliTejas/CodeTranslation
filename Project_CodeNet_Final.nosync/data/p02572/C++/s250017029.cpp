#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
const int MOD = 1000000007;
const int N = 2e6+13, M = N;
int main()
{
    IOS;
    lli n;
    cin>>n;
    lli arr[n];
    lli ans=0;
    lli sum=0;
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
        ans+=arr[i]*sum%MOD;
        sum+=arr[i];
        sum%=MOD;
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}