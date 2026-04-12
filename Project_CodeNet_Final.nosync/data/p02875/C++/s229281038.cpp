#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long i64;
inline int rd(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e7+5, P = 998244353;
int n, ans, pw[N]; i64 iv[N]; void fix(int &x) { x<P?0:x-=P; }
int main()
{
    n = rd(); pw[0] = iv[1] = 1, pw[1] = 2, ans = 3; 
    for(int i = 2; i <= n; ++i) ans = ans*3ll%P, iv[i] = P-(P/i)*iv[P%i]%P, fix(pw[i]=pw[i-1]<<1);
    ans = P-ans; for(int i = 0, m = n>>1, v = 1, w = 0; i <= m; ++i) 
        fix(w += (i64)v*pw[m-i]%P), fix(ans += (i64)v*w%P*pw[i+1]%P), v = v*iv[i+1]%P*(m-i)%P;
    printf("%d\n", ans);
    return 0;
}