#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

std::string n;
int f[1010][10];
int dig[1010];
int k, len;

int dfs(int dep, bool isLimit, int status)
{
    if (status > k) return 0;
    if (!dep)   return status == k;
    if (!isLimit && ~f[dep][status])   return f[dep][status];
    int ans = 0, bit = isLimit ? dig[dep] : 9;
    for (int i = 0; i <= bit; ++i)
    {
        if (i) ans += dfs(dep - 1, isLimit && i == bit, status + 1);
        else    ans += dfs(dep - 1, isLimit && i == bit, status);
    }
    if (!isLimit)   f[dep][status] = ans;
    return ans;
}

int main()
{
    memset(f, -1, sizeof(f));
    std::cin >> n;
    read(k);
    len = n.size();
    for (int i = 0; i < len; ++i)   dig[len - i] = n[i] - 48;
    printf("%d\n", dfs(len, true, 0));
    return 0;
}