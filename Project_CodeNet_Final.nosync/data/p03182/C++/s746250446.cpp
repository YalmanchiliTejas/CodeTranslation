#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MaxN = 2e5 + 25;

int n, m;

struct segmentTree{
    long long tree[MaxN * 4];
    long long p[MaxN * 4];

    void clear()
    {
        memset(p, 0, sizeof(p));
        memset(tree, 0, sizeof(tree));
    }

    void up(int pref, int delta)
    {
        up(1, 0, n + 1, 0, pref, delta);
    }
    void upPos(int pos, long long delta)
    {
        up(1, 0, n + 1, pos, pos, delta);
    }
    void up(int x, int l, int r, int ll, int rr, long long delta)
    {
        if(l > rr || r < ll)
            return;
        if(l >= ll && r <= rr)
        {
            tree[x] += delta;
            p[x] += delta;
            return;
        }

        push(x);
        int mid = (l + r) / 2;

        up(x + x, l, mid, ll, rr, delta);
        up(x + x + 1, mid + 1, r, ll, rr, delta);

        tree[x] = min(tree[x + x], tree[x + x + 1]);
    }

    void push(int x)
    {
        if(p[x])
        {
            tree[x + x] += p[x];
            tree[x + x + 1] += p[x];
            p[x + x] += p[x];
            p[x + x + 1] += p[x];
            p[x] = 0;
        }
    }

    long long getMin()
    {
        return tree[1];
    }
} segmentTree;

vector<pair<int, int> > v[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    long long sum = 0;

    for(int i = 1; i <= m; ++i)
    {
        int l, r, a;
        cin >> l >> r >> a;
        v[r].push_back(make_pair(l, a));

        sum += a;
    }

    for(int i = 1; i <= n + 1; ++i)
    {
        for(auto p : v[i - 1])
            segmentTree.up(p.first - 1, p.second);
        segmentTree.upPos(i, segmentTree.getMin());
    }

    cout << sum - segmentTree.getMin() << '\n';

    return 0;
}

