#include <bits/stdc++.h>
#define fup(i,a,b) for(int i=a;i<=b;++i)
#define fdw(i,a,b) for(int i=a;i>=b;--i)
#define sync ios::sync_with_stdio(false);cin.tie(0)
#define cl(a) memset(a,0,sizeof(a))
#define gcd __gcd
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll ksm(ll a,ll b,ll mod){ll ans=1;a%=mod;for(;b;b>>=1){if(b&1) ans=ans*a%mod;a=a*a%mod;}return ans;}
//ll oula(ll n){ ll res=n;for(ll i=2;i*i<=n;i++){if(n%i==0){ res=res-res/i;while(n%i==0) n/=i;}}if(n>1) res=res-res/n;return res;}
//bool MRT(ll x){if(x==2)return true;fup(i,1,30){ll now=rand()%(x-2)+2;if(ksm(now,x-1,x)!=1)return false;}return true;}
//void shai(int n)fup(i,2,n){if(isprime[i]){v.push_back(i);for(int j=2*i;j<=10000;j+=i)isprime[j]=0;}}//"埃氏筛筛选素数"
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int N = 2e5 + 10 ;
ll dp[102][2][5];
string s;
int k, n;
ll f(int i, bool b, int c) {
    if (c == 0) return 1;
    if (i == n) return 0;
    if (dp[i][b][c] > 0) return dp[i][b][c];
    int d = s[i] - '0';
    ll res = 0;
    if (b) {
        if (d == 0) {
            res = f(i + 1, true, c);
        } else {
            res = f(i + 1, true, c - 1) + (d - 1) * f(i + 1, false, c - 1) + f(i + 1, false, c);
        }
    } else {
        res = 9 * f(i + 1, false, c - 1) + f(i + 1, false, c);
    }
    return dp[i][b][c] = res;
}

int main() 
{
    cin >> s >> k;
    n = s.size();
    ll ans = f(0, true, k);
    cout << ans << endl;
    return 0;
}
