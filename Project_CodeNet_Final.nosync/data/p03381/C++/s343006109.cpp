#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int maxn = 2e5+50;

struct node
{
    int x;
    int id;
    friend bool operator < (const node &a, const node &b)
    {
        return a.x < b.x;
    }
} st[maxn];

int ans[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &st[i].x);
        st[i].id = i;
    }
    sort(st, st + n);
    for (int i = 0; i < n; ++i)
    {
        if (i < n/2) ans[st[i].id] = st[n/2].x;
        else ans[st[i].id] = st[n/2-1].x;
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
