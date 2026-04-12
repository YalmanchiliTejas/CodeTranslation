#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    vector <int> N(n+1),Q(n+1);
    for(int i=1;i<=n;i++) cin>>N[i];
    int sm=0;
    for(int i=1;i<=n;i++) sm+=N[i],Q[i]=sm;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        sum= ( sum+ ( N[i] * ((Q[n]-Q[i])%mod) ) %mod )%mod;
    }
    cout<<sum<<endl;
    return 0;
}
/*


*/

