#include<bits/stdc++.h> 
#define Re register
#define fo(i, a, b) for (Re int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (Re int i = (a); i >= (b); --i)
#define edge(i, u) for (Re int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define pb push_back
#define F first
#define S second
#define ll long long
#define inf 10000000000007
#define mp std::make_pair
#define lowbit(x) (x & -x)
#define eps 1e-4
#define itset std::set<node>::iterator
#define lb lower_bound
#define N 55
#define ls (k << 1)
#define rs (k << 1 | 1)
#define M 260
int f[N][N][N][N], a[N][N], b[N][N], ans, n;
int main ()
{
    scanf("%d", &n);
    if (n == 5 || n == 3 || n == 7)
        printf("YES");
    else
        printf("NO");
    return 0;
}