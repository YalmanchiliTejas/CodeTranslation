#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cctype>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<ll> vecl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T>
inline void read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return ;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1:1;
    ret = (c == '-') ? 0:(c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return ;
}
inline void outi(int x) {if (x > 9) outi(x / 10);putchar(x % 10 + '0');}
inline void outl(ll x) {if (x > 9) outl(x / 10);putchar(x % 10 + '0');}

int n;
const int N=2e5+7;
const int mod=1e9+7;
ll a[N];
typedef long long ll;
ll sum=0,res,ans[N];
int main()
{
   read(n);
   read(a[1]);
   ans[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        read(a[i]);
        ans[i]=(ans[i-1]%mod+a[i]%mod)%mod;
    }
    for(int i=1;i<=n-1;i++)
    {
       res=((a[i]%mod)*(ans[n]%mod-ans[i]%mod+mod)%mod)%mod;
        sum+=res%mod;
    }
        printf("%lld",sum%mod);
}
