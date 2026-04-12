#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(a,b,c) for(int a=b; a<c; a++)
#define frr(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define pii pair<int,int>
#define R(a) ll a; cin >> a;
#define RS(a) string  a; cin >> a;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;

#define RA(a, n) ll a[(n) + 1] = {}; fr(i, 1, (n)+1) {cin >> a[i];}
#define RM(a, n, m) int a[n + 1][m + 1] = {}; fr(i, 1, n+1) {fr(j, 1, m+1) cin >> a[i][j];}
#define reset(X) memset(X, 0, sizeof(X))
using vi=vector<int>;
const int inf = 1e18;
const int mod=1e9+7;
unsigned int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
bool isPrime(int n)
{   if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}
int modInverse(int n, int p)
{
    return power(n, p-2, p);
}
signed main()
{
    fastio;
    R(n);RA(a,n);
    int p[n+2];
    reset(p);
    frr(i,n,1)
    {
        p[i]=(p[i+1]+a[i])%mod;
       // cout<<p[i]<<endl;
    }
    int ans=0;
    fr(i,1,n+1)
    {
        ans=(ans+(a[i]*p[i+1])%mod)%mod;
    }
    cout<<ans<<endl;

}
