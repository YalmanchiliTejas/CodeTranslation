#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> p(n);
        int ma = 0, mi = 1e9 + 5;
        rep(i, n) {
                scanf("%d%d", &p[i].first, &p[i].second);
                ma = max(ma, max(p[i].first, p[i].second));
                mi = min(mi, min(p[i].first, p[i].second));
        }
        int c = 0;
        rep(i, n) {
                c += (p[i].first == ma || p[i].second == ma || p[i].first == mi || p[i].second == mi);
        }
        long long ans = 1e18 + 5;
        if (c != 1) {
                rep(i, n) {
                        if (p[i].first > p[i].second) {
                                swap(p[i].first, p[i].second);
                        }
                }
                sort(p.begin(), p.end());
                int v = p.back().first;
                int u = 1e9 + 5;
                rep(i, n) {
                        ans = min(ans, (long long) (v - min(p[i].first, u)) * (ma - mi));
                        v = max(v, p[i].second);
                        u = min(u, p[i].second);
                }
        }
        vector<int> l, r;
        rep(i, n) {
                if (p[i].first > p[i].second) {
                        l.push_back(p[i].first);
                        r.push_back(p[i].second);
                } else {
                        r.push_back(p[i].first);
                        l.push_back(p[i].second);
                }
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        ans = min(ans, (long long) (l.back() - l.front()) * (r.back() - r.front()));
        printf("%lld\n", ans);
        return 0;
}
