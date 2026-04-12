// https://atcoder.jp/contests/abc134/tasks/abc134_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    multiset<int, greater<int>> st;
    REP(i, N) {
        int t;
        cin >> t;
        auto it = st.lower_bound(t - 1);
        // 検索値より小さい値が見つかったら削除
        if (it != st.end()) {
            st.erase(it);
        }
        st.insert(t);
    }
    cout << st.size() << endl;

    return 0;
}
