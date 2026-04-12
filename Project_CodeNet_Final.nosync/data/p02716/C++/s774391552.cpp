#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
//#define mod2 20071027
//#define MOD 998244353
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a) for(int i=1;i<=a;i++)
#define base 139
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case #%lld: ", ++c)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const ll N=200010,M=1000010;
ll n, a[N], mem[N][4], vis[N][4];
ll dp(ll pos, ll c)
{
    if(pos>n) return 0;
    ll &ret=mem[pos][c];
    if(vis[pos][c]) return ret;
    vis[pos][c]=1;
    ret=a[pos];
    if(c==2)
    {
        ret+=max(dp(pos+2, c), max(dp(pos+3, c-1), dp(pos+4, c-2)));
    }
    else if(c==1)
        ret+=max(dp(pos+2, c),dp(pos+3, c-1));
    else ret+=dp(pos+2, c);
    return ret;
}
int main()
{
    in1(n);
    for(int i=1;i<=n;i++)
        in1(a[i]);
    memz(vis);
    ll c, res=MIN;
    if(n%2) c=2;
    else c=1;
    res= dp(1, c);
    memz(vis);
    res=max(res, dp(2, c-1));
    memz(vis);
    if(n%2) res = max(res, dp(3, c-2));
    printf("%lld\n", res);
    return 0;
}

/*

*/
