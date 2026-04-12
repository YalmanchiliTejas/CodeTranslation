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

pair<long long,long long> T[MAXN][MAXN];

pair <long long, long long> rec(int l, int r)
{
    int t = (l + n - r - 1) % 2;
    if(l == r)
    {
        if(t == 0) return {a[l], 0};
        if(t == 1) return {0, a[l]};
    }
    if(T[l][r].first != 0 || T[l][r].second != 0)
    {
        return T[l][r];
    }
    long long f;
    if(t == 0) f = rec(l, r - 1).first + a[r];
    else f = rec(l, r - 1).second + a[r];
    long long s;
    if(t == 0) s = rec(l + 1, r).first + a[l];
    else s = rec(l + 1, r).second + a[l];


    if(t == 1)
    {
        if(f > s)
        {
            return T[l][r] = {rec(l, r - 1).first, f};
        }
        else
        {
            return T[l][r] = {rec(l + 1, r).first, s};
        }
    }
    else
    {
        if(f > s)
        {
            return T[l][r] = {f, rec(l, r - 1).second};
        }
        else
        {
            return T[l][r] = {s, rec(l + 1, r).second};
        }
    }
}

void solve()
{
    long long X = rec(0, n - 1).first;
    //printf("%lld\n", X);
    printf("%lld\n", 2 * X - z);
}

int main()
{
    read_input();
    solve();

    return 0;
}
