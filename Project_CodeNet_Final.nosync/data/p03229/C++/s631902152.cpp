// https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];
    sort(ALL(v));
    vector<ll> sum(2, 0);
    ll before = 0;
    REP(i, 2) {
        if (i == 1) {
            reverse(ALL(v));
        }
        deque<int> q, t;
        REP(i, n) q.push_back(v[i]);

        t.push_back(q.front());
        q.pop_front();
        REP(i, n - 1) {
            if (i % 4 <= 1) {
                if (i % 4 == 0) {
                    t.push_front(q.back());
                } else {
                    t.push_back(q.back());
                }
                q.pop_back();
            } else {
                if (i % 4 == 2) {
                    t.push_front(q.front());
                } else {
                    t.push_back(q.front());
                }
                q.pop_front();
            }
        }
        bool first = true;
        for (auto x : t) {
            if (first) {
                first = false;
            } else {
                sum[i] += abs(x - before);
            }
            before = x;
        }
    }

    cout << max(sum[0], sum[1]) << endl;

    return 0;
}
