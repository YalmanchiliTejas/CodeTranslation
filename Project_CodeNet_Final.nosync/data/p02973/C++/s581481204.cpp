#include<vector>
#include<queue>
#include<stdio.h>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#define mp make_pair
using namespace std;
typedef long long ll;
inline ll in()
{
    ll res=0,p=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') p=-1; c=getchar();}
    while(c>='0'&&c<='9') res=res*10+c-48,c=getchar();
    return p*res;
}
void out(ll x)
{
    if (x>9) out(x/10);
    putchar(x%10+48);
}
void outc(ll x)
{
    if (x<0){
        putchar('-');
        out(-x);
    }else out(x);
    putchar(32);
}
void outn(ll x)
{
    if (x<0){
        putchar('-');
        out(-x);
    }else out(x);
    putchar(10);
}
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
//const double pi = acos(-1.0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll quickpow(ll x, int k)
{
    ll res = 1;
    while(k){
        if(k & 1) res = (res * x) % mod;
        k >>= 1, x = (x * x) % mod;
    }
    return res;
}
//ll C(int n, int m){return (fac[n] * quickpow((fac[m] * fac[n - m]) % mod, mod - 2)) % mod;}
//Unaccepted
const int maxn = 1e5 + 10;
int dp[100005];
vector<int> vi;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        vi.emplace_back(x);
    }
    reverse(vi.begin(), vi.end());
    memset(dp, 0x3f, sizeof(dp));
    for (int x : vi){
        *upper_bound(dp, dp + n, x) = x;
    }
    cout << lower_bound(dp, dp + n, 0x3f3f3f3f) - dp << endl;
	return 0;
}
