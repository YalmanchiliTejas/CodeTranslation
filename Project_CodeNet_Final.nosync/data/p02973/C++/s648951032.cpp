#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
using ll = long long;
using namespace std;
const int INF32       = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7        = 1'000'000'007;
const int MOD9        = 1'000'000'009;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &&i : A) {
        cin >> i;
    }

    int ans = 0;
    multiset<int> st;
    REP(i, N) {
        if (st.empty()) {
            ans++;
            st.insert(A[i]);
        } else {
            auto stitr = st.lower_bound(A[i]);
            if (stitr == st.begin()) {
                ans++;
                st.emplace(A[i]);
            } else {
                stitr--;
                st.erase(stitr);
                st.emplace(A[i]);
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}