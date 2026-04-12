#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, x, m;

lint f(lint z) {
    return z * z % m;
}

lint solve_short() {
    lint now = x;
    lint res = 0;
    for (int i = 0; i < n; i++) {
        res += now;
        now = f(now);
    }
    return res;
}

bool be_zero() {
    lint now = x;
    for (int i = 0; i <= m; i++) {
        now = f(now);
    }
    return now == 0;
}

vector<lint> loop() {
    set<lint> st;
    lint now = x;
    vector<lint> res;
    while (true) {
        res.push_back(now);
        if (st.count(now)) {
            return res;
        } else {
            st.insert(now);
            now = f(now);
        }
    }
}

int main() {
    cin >> n >> x >> m;
    if (n < 1000000) {
        cout << solve_short() << endl;
        return 0;
    }
    if (be_zero()) {
        lint now = x;
        lint res = 0;
        while (now != 0) {
            res += now;
            now = f(now);
        }
        cout << res << endl;
        return 0;
    } else {
        auto l = loop();
        // for (auto e : l) {
        //    cout << e << endl;
        //}
        lint loop_last = l.back();
        l.pop_back();
        lint k = l.size();
        lint left = 0;
        lint right = k;
        for (int i = 0; i < k; i++) {
            if (l[i] == loop_last) {
                left = i;
                break;
            }
        }
        lint ans = 0;
        for (int i = 0; i < left; i++) {
            ans += l[i];
        }
        n -= left;
        lint unit = 0;
        for (int i = left; i < right; i++) {
            unit += l[i];
        }
        lint loop_len = right - left;
        ans += unit * (n / loop_len);
        n %= loop_len;
        for (int i = 0; i < n; i++) {
            ans += l[left + i];
        }
        cout << ans << endl;
    }
}