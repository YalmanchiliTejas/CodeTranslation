
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)
#define int long long

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
    T f = 1, x = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return f * x;
}

const int INF = 0x3f3f3f3f, N = 100003, M = N << 1;

int n, x, m;
int ans, cnt, sum[N];
int vis[N];

signed main()
{
    //File("");
    n = gi <int> (), x = gi <int> (), m = gi <int> ();
    if (n <= 1000000)
    {
    	int kk = x;
    	for (int i = 1; i <= n; i+=1)
    		ans += kk % m, kk = kk * kk % m;
    	printf("%lld\n", ans);
    	return 0;
    }
    vis[x] = 1;
    int now = x * x % m;
    sum[1] = x, cnt = 1;
    while (!vis[now]) 
    	++cnt, sum[cnt] = sum[cnt - 1] + now, vis[now] = cnt, now = now * now % m;
    int len = cnt + 1 - vis[now], qd = vis[now];
    if (n <= qd)
    {
    	int kk = x;
    	for (int i = 1; i <= n; i+=1)
    		ans += kk % m, kk = kk * kk % m;
    	printf("%lld\n", ans);
    	return 0;
    }
    int tmp = sum[cnt] - sum[qd - 1];
    ans = sum[qd - 1];
    n -= (qd - 1);
    int cs = n / len, ys = n % len;
    //cout << cs << ' ' << ys << endl;
    cout << ans + tmp * cs + sum[qd + ys - 1] - sum[qd - 1] << endl;
    //cout << len << ' ' << qd << endl;
    return 0;
}