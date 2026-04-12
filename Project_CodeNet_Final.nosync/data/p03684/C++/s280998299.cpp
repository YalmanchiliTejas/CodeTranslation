#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int id, x, y;
};

const int MAXN = 1E5;
int parent[MAXN + 1];
int s[MAXN + 1];
Point pts[MAXN + 1];
tuple<int, int, int> edges[2 * (MAXN - 1)];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (s[r1] < s[r2])
        swap(r1, r2);
    parent[r2] = r1;
    s[r1] += s[r2];
}

bool cmpx(Point a, Point b)
{
    return a.x < b.x;
}

bool cmpy(Point a, Point b)
{
    return a.y < b.y;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        s[i] = 1;
        pts[i].id = i;
        cin >> pts[i].x >> pts[i].y;
    }
    sort(pts + 1, pts + n + 1, cmpx);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        edges[cnt++] = make_tuple(pts[i + 1].x - pts[i].x, pts[i].id, pts[i + 1].id);
    }
    sort(pts + 1, pts + n + 1, cmpy);
    for (int i = 1; i < n; i++)
    {
        edges[cnt++] = make_tuple(pts[i + 1].y - pts[i].y, pts[i].id, pts[i + 1].id);
    }
    sort(edges, edges + cnt);
    long long ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        int a = get<1>(edges[i]);
        int b = get<2>(edges[i]);
        if (getRoot(a) != getRoot(b))
        {
            ans += get<0>(edges[i]);
            mge(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}
