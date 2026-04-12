#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e4+5, P = 998244353;
int n, s, t, f[N][N];
int64 fac[N], ifac[N], ans;
char a[N], b[N];
int64 inv(int i) { return i == 1?1:P-P/i*inv(P%i)%P; }
int64 C(int n, int m) { return fac[n]*ifac[m]%P*ifac[n-m]%P; }
int main()
{
    scanf("%s", a+1), scanf("%s", b+1);
    for(int i = 1; a[i]; ++i) 
        if(a[i] == '1'&&b[i] == '1') ++s, ++n;
        else if(a[i] == '1'&&b[i] == '0') ++t, ++n;
    fac[0] = ifac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i-1]*i%P;
    ifac[n] = inv(fac[n]);
    for(int i = n-1; i; --i) ifac[i] = ifac[i+1]*(i+1)%P;
    for(int i = 0; i <= t; ++i) f[0][i] = fac[i]*fac[i]%P;
    for(int i = 1; i <= s; ++i)
        for(int j = 1; j <= t; ++j)
            f[i][j] = (1ll*f[i-1][j]*i%P*j%P+1ll*f[i][j-1]*j%P*j%P)%P; 
    for(int i = 0; i <= s; ++i) ans = (ans+fac[i]*fac[i]%P*C(n, i)%P*C(s, i)%P*f[s-i][t]%P)%P;
    printf("%lld\n", ans);
    return 0;
}