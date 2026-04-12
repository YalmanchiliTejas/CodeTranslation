#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

struct St {
    deque<int> q;
    bool flip{false};

    void add(int x) {
        if (flip)
            q.push_front(x);
        else
            q.push_back(x);
    }

    void print() {
        if (flip)
            reverse(q.begin(), q.end());
        for (int x : q)
            cout << x << " ";
        cout << '\n';
    }
};

int main() {
#ifdef LOCAL
    // freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    St st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.add(x);
        st.flip = !st.flip;
    }
    st.print();
}