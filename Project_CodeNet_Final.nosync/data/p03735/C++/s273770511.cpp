#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        A.push_back(make_pair(x, i));
        A.push_back(make_pair(y, i));
    }
    sort(A.begin(), A.end());
    int vmax = A.back().first, imax = A.back().second;
    A.erase(A.end() - 1);
    int vmin = A.front().first, imin = A.front().second;
    A.erase(A.begin());

    int64_t ans = 0;
    {
        vector<bool> used(n, false);
        used[imin] = true;
        int left = 0;
        int bmax = vmin;
        int rmin = vmax;
        while (left < SZ(A)) {
            if (!used[A[left].second]) {
                bmax = A[left].first;
            } else {
                rmin = min(rmin, A[left].first);
            }
            used[A[left].second] = true;
            left++;
        }
        ans = (int64_t) (vmax - rmin) * (bmax - vmin);
    }
    if (imax != imin) {
        int len = -1;
        for (int step = 1 << 29; step > 0; step /= 2) {
            vector<int> cnt(n, 0);
            int clen = len + step;
            int have = 0;
            bool ok = false;
            for (int i = 0, j = 0; i < SZ(A) && !ok; ++i) {
                while (j < SZ(A) && A[j].first - A[i].first <= clen) {
                    cnt[A[j].second]++;
                    if (cnt[A[j].second] == 1) {
                        have++;
                    }
                    j++;
                }
                if (have == n) {
                    ok = true;
                }
                cnt[A[i].second]--;
                if (cnt[A[i].second] == 0) {
                    have--;
                }
            }
            if (!ok) {
                len = clen;
            }
        }
        len++;
        ans = min(ans, (int64_t) (vmax - vmin) * len);
    }
    cout << ans << '\n';
}
