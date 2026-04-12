#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define SIZE 200005
#define UF_MAX 100005
using namespace std;
typedef long double ld;
typedef long long int lli;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
lli MOD = 1000000007;
#define UF_MAX 100005
struct UFind {
    int par[UF_MAX];
    int rank[UF_MAX];
    int count[UF_MAX];
    UFind(int n)
    {
        rep(i, n)
        {
            par[i] = i;
            rank[i] = 0;
            count[i] = 1;
        }
    }
    int find(int x)
    {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y]) {
            par[x] = y;
            count[y] += count[x];
        } else {
            par[y] = x;
            count[x] += count[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

using p = pair<lli, pair<lli, lli>>;
int main()
{
    priority_queue<p, vector<p>, greater<p>> q;
    int n;
    lli x, y;
    cin >> n;
    vector<pair<lli, lli>> X, Y;
    rep(i, n)
    {
        cin >> x >> y;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    rep(i, n - 1)
    {
        q.push(make_pair(X[i + 1].first - X[i].first, make_pair(X[i + 1].second, X[i].second)));
        q.push(make_pair(Y[i + 1].first - Y[i].first, make_pair(Y[i + 1].second, Y[i].second)));
    }
    UFind u(n);
    int cnt = 0;
    lli ans = 0;
    while (cnt < n - 1) {
        auto s = q.top();
        q.pop();
        int l = s.second.first;
        int r = s.second.second;

        if (u.same(l, r)) {
            continue;
        }
        u.unite(l, r);
        cnt++;
        ans += s.first;
    }
    cout << ans << endl;
}
