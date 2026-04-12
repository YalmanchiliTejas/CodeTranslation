#include<bits/stdc++.h>

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define sc(a) scanf("%c",&a)
#define ss(a) scanf("%s",a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pc(a) putchar(a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i, a, b) for(register int i=a;i<=b;++i)
#define repd(i, a, b) for(register int i=a;i>=b;--i)
#define reps(s) for(register int i=head[s];i;i=Next[i])
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define mii unordered_map<int,int>
#define msi unordered_map<string,int>
#define lowbit(x) ((x)&(-(x)))
#define ce(i, r) i==r?'\n':' '
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;

inline int qr() {
    int f = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}

const int N = 2e5 + 10, MOD = 1e9 + 7;
int a[N], n;
ll b[N];

int main() {
    n = qr();
    repi(i, 1, n)a[i] = qr();
    repd(i, n, 1)b[i] = (b[i + 1] + a[i]) % MOD;
    ll ans = 0;
    repi(i, 1, n - 1)ans = (ans + a[i] * b[i + 1] % MOD) % MOD;
    pl(ans);
    return 0;
}
