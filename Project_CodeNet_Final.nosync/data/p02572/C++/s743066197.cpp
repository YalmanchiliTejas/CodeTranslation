#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int32_t main()
{
    int n;
    cin>>n;
    vector<int>A(n);
    int s = 0;
    int x = 0;
    for (int i = 0;i<n;i++){cin>>A[i];s+=A[i];s%=mod;if (A[i]>=1e5)A[i]-=mod;x+=A[i]*A[i];x%=mod;}
    if (s>=1e5)s-=mod;
    s = s * s;
    s%=mod;
    x%=mod;
    int ans = (s - x)%mod;
    if (ans%2!=0)ans+=mod;
    ans/=2;
    cout<<(ans+mod)%mod;
    return 0;
}