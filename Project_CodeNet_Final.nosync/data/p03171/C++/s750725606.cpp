#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 3 * 1e3 + 5;

int n;
long long a[MAXN];
long long z;

void read_input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        z += a[i];
    }
}

pair<long long,long long> T[MAXN][MAXN][2];

pair <long long, long long> rec(int l, int r, int t)
{
    if(l == r)
    {
        if(t == 0) return {a[l], 0};
        if(t == 1) return {0, a[l]};
    }
    if(T[l][r][t].first != 0 || T[l][r][t].second != 0)
    {
        return T[l][r][t];
    }
    long long f;
    if(t == 0) f = rec(l, r - 1, t ^ 1).first + a[r];
    else f = rec(l, r - 1, t ^ 1).second + a[r];
    long long s;
    if(t == 0) s = rec(l + 1, r, t ^ 1).first + a[l];
    else s = rec(l + 1, r, t ^ 1).second + a[l];

    if(t == 1)
    {
        if(f > s)
        {
            return T[l][r][t] = {rec(l, r - 1, t ^ 1).first, f};
        }
        else
        {
            return T[l][r][t] = {rec(l + 1, r, t ^ 1).first, s};
        }
    }
    else
    {
        if(f > s)
        {
            return T[l][r][t] = {f, rec(l, r - 1, t ^ 1).second};
        }
        else
        {
            return T[l][r][t] = {s, rec(l + 1, r, t ^ 1).second};
        }
    }
}

void solve()
{
    long long X = rec(0, n - 1, 0).first;
    //printf("%lld\n", X);
    printf("%lld\n", 2 * X - z);
}

int main()
{
    read_input();
    solve();

    return 0;
}
