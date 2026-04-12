#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int n, uf_par[112345], uf_rnk[112345];

void uf_init(int size)
{
    REP(i, size)
    {
        uf_par[i] = i;
        uf_rnk[i] = 0;
    }
}

int uf_find(int x)
{
    if (uf_par[x] == x)
        return x;
    else
        return uf_par[x] = uf_find(uf_par[x]);
}

void uf_unite(int x, int y)
{
    x = uf_find(x);
    y = uf_find(y);
    if (x == y)
        return;

    if (uf_rnk[x] < uf_rnk[y])
    {
        uf_par[x] = y;
    }
    else
    {
        uf_par[y] = x;
        if (uf_rnk[x] == uf_rnk[y])
            uf_rnk[x]++;
    }
}

bool uf_same(int x, int y)
{
    return uf_find(x) == uf_find(y);
}

int main()
{
    int n;
    vector<P> x, y;
    map<P, bool> mp;

    cin >> n;

    uf_init(n);

    int num = n;

    REP(i, n)
    {
        int a, b;
        cin >> a >> b;
        if (mp[make_pair(a, b)])
        {
            num--;
            continue;
        }

        mp[make_pair(a, b)] = true;

        x.push_back(make_pair(a, i));
        y.push_back(make_pair(b, i));
    }

    SORT(x);
    SORT(y);

    vector<pair<int, P>> v;

    for (int i = 0; i < x.size() - 1; i++)
    {
        v.push_back(make_pair(x[i + 1].first - x[i].first, make_pair(x[i].second, x[i + 1].second)));
    }

    for (int i = 0; i < y.size() - 1; i++)
    {
        v.push_back(make_pair(y[i + 1].first - y[i].first, make_pair(y[i].second, y[i + 1].second)));
    }

    SORT(v);

    ll res = 0;
    int cnt = 0;

    int i = 0;

    while (cnt < num - 1)
    {
        if (uf_same(v[i].second.first, v[i].second.second))
        {
            i++;
            continue;
        }

        res += v[i].first;

        uf_unite(v[i].second.first, v[i].second.second);

        cnt++;

        i++;
    }

    cout << res << endl;

    return 0;
}