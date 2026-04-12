#include <bits/stdc++.h>
#define lli long long int
using namespace std;
#define mod 1000000007
#define MOD 1000000037
#define mod1 998244353
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define INF 1e18
#define common cout << "Case #" << w+1 << ": "  



int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    vector<int>cum(n);
    int temp=0;
    for(int i=n-1;i>-1;i--)
    {
        temp=(temp*1LL+v[i])%mod;
        cum[i]=temp;
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans=(ans*1LL+(v[i]*1LL*cum[i+1])%mod)%mod;
    }
    cout << ans << endl;
}