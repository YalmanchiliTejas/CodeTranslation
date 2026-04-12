#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

class union_find {
public:
    union_find(int n)
    {
        for (int i = 0; i < n; i++) {
            v.push_back(i);
        }
    }

    void unite(int a, int b)
    {
        v[find(a)] = find(b);
    }

    int find(int i)
    {
        if (v[i] == i)
            return i;
        return v[i] = find(v[i]);
    }

    vector<int> v;
};

int main()
{
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> ps(n);
    for (auto& p : ps)
        cin >> p.first >> p.second;

    vector<int> xord(n), yord(n);
    for (int i = 0; i < n; i++) {
        xord[i] = i;
        yord[i] = i;
    }

    sort(xord.begin(), xord.end(), [&](int a, int b) { return ps[a].first < ps[b].first; });
    sort(yord.begin(), yord.end(), [&](int a, int b) { return ps[a].second < ps[b].second; });

    vector<pair<int64_t, pair<int, int>>> g;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            g.push_back(make_pair(ps[xord[i]].first - ps[xord[i - 1]].first, make_pair(xord[i], xord[i - 1])));
            g.push_back(make_pair(ps[yord[i]].second - ps[yord[i - 1]].second, make_pair(yord[i], yord[i - 1])));
        }
        if (i + 1 < n) {
            g.push_back(make_pair(ps[xord[i + 1]].first - ps[xord[i]].first, make_pair(xord[i + 1], xord[i])));
            g.push_back(make_pair(ps[yord[i + 1]].second - ps[yord[i]].second, make_pair(yord[i + 1], yord[i])));
        }
    }

    union_find uf(n);
    sort(g.begin(), g.end());

    int64_t ans = 0;

    for (int i = 0; i < g.size(); i++) {
        int a = g[i].second.first;
        int b = g[i].second.second;
        if (uf.find(a) == uf.find(b))
            continue;
        uf.unite(a, b);
        ans += g[i].first;
    }

    cout << ans << endl;

    /*
    vector<bool> done(n, false);
    done[0] = true;

    int xmin = ps[0].first;
    int xmax = xmin;
    int ymin = ps[0].second;
    int ymax = ymin;

    int xl, xr, yl, yr;
    for (int i = 0; i < n; i++) {
        if (xord[i] == 0) {
            xl = xr = i;
        }
        if (yord[i] == 0) {
            yl = yr = i;
        }
    }

    int64_t ans = 0;
    for (int i = 1; i < n; i++) {
        int best_t = -1;
        int64_t best_d = 0x7fffffffL;
        if (xl - 1 >= 0) {
            best_t = 0;
            best_d = ps[xord[xl]].second - ps[xord[xl - 1]].second;
        }
        if (xr + 1 < n && ps[xord[xr + 1]].second - ps[xord[xr]].second < best_d) {
            best_t = 0;
            best_d = ps[xord[xr + 1]].second - ps[xord[xr]].second;
        }
        if (yl - 1 >= 0 && ps[yord[yl]].second - ps[yord[yl - 1]].second < best_d) {
            best_t = 0;
            best_d = ps[yord[yl]].second - ps[yord[yl - 1]].second;
        }
        if (yr + 1 < n && ps[yord[yr + 1]].second - ps[yord[yr]].second < best_d) {
            best_t = 0;
            best_d = ps[yord[yr + 1]].second - ps[yord[yr]].second;
        }

        ans += best_d;
        if (best_t == 0) {
            done[] = true;
            xl--;
        }
    }
*/

    return 0;
}
