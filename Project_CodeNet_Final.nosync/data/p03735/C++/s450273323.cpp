#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4 * (int)1e5 + 10;
int x[maxN], y[maxN];
int a[2 * maxN];
int n;
int cnt[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > all;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        all.emplace_back(x[i], 2 * i);
        all.emplace_back(y[i], 2 * i + 1);
        a[2 * i] = x[i];
        a[2 * i + 1] = y[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(all.begin(), all.end());
    int rmin = all[0].first;
    ll best = 3e18;
    if (all.back().second / 2 != all[0].second / 2) {
        int posmin = all[0].second / 2;
        int posmax = all.back().second / 2;
        int rmax = all.back().first;
        set < pair < int, int > > cur_mins;
//        set < pair < int, int > > all_cands;

        for (int i = 0; i < n; i++) {
            if (i != posmin && i != posmax) {
                cnt[i] = 2;
//                all_cands.insert({a[2 * i], 2 * i});
//                all_cands.insert({a[2 * i + 1], 2 * i + 1});
                cur_mins.insert(min(make_pair(a[2 * i], 2 * i), make_pair(a[2 * i + 1], 2 * i + 1)));
            }
            else {
                cnt[i] = 1;
                int who;
                if (i == posmin) who = all[0].second ^ 1;
                else who = all.back().second ^ 1;
//                all_cands.insert({a[who], who});
                cur_mins.insert({a[who], who});
            }
        }
        for (int i = 0; i + 1 < all.size(); i++) {
            if (i > 1) {
                int to_del = all[i - 1].second;
                cnt[to_del / 2]--;
                if (cnt[to_del / 2] == 0) break;
                if (make_pair(a[to_del], to_del) < make_pair(a[to_del ^ 1], (to_del ^ 1))) {
                    cur_mins.erase({a[to_del], to_del});
                    cur_mins.insert({a[to_del ^ 1], (to_del ^ 1)});
                }
            }
            auto it = *(--cur_mins.end());
            if (it < all[i]) continue;
            best = min(best, 1LL * (rmax - rmin) * (it.first - all[i].first));
        }
    }
    int bmax = all.back().first;
    int posmin = all[0].second / 2;
    int posmax = all.back().second / 2;
    int rmax = rmin;
    int bmin = bmax;
    for (int i = 0; i < n; i++) {
        if (posmin == i) {
            bmin = min(bmin, a[all[0].second ^ 1]);
        }
        else if (posmax == i) {
            rmax = max(rmax, a[all.back().second ^ 1]);
        }
        else {
            rmax = max(rmax, min(a[2 * i], a[2 * i + 1]));
            bmin = min(bmin, max(a[2 * i], a[2 * i + 1]));
        }
    }
    best = min(best, 1LL * (rmax - rmin) * (bmax - bmin));
    cout << best;
    return 0;
}