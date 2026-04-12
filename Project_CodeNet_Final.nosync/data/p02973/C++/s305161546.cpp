#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    multiset<int> st;

    rep(i, n) {
        if (st.empty()) {
            st.insert(a[i]);
        }
        else {
            auto it = st.lower_bound(a[i]);
            if (it == st.begin()) {
                st.insert(a[i]);
            }
            else {
                it--;
                st.erase(it);
                st.insert(a[i]);
            }
        }
    }

    cout << st.size() << endl;
    return 0;
}