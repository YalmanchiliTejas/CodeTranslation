#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow2(x) (ll(1)<<x)
#define pb push_back
#define mp make_pair
#define w(t) int t;scanf("%d",&t);while(t--)
#define For(i,a,n) for(int i=a;i<n;i++)
#define scan(n) int n;scanf("%d", &n);
using namespace std;
const int sz = 1e3 + 5;
const int mod = 1e9 + 7;
int main()
{
    scan(n);
    ll x[n], ans = 0,sum = 0;
    For(i,0,n)
    {
        scanf("%lld", &x[i]);
        ans = (ans + x[i]  * sum) % mod;
        sum = (sum + x[i]) % mod;
    }
    cout<<ans;
}
