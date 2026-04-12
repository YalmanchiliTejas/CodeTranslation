#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const int N = 200'000;
const ll INF = 200'000'000'000'001ll;
int n;
ll a[N + 1];
ll mem[N + 2][2][3][3];
bool in_mem[N + 2][2][3][3];
ll opt(int i, bool gap_front, int gap2, int gap3) {
    ll& ans = mem[i][gap_front][gap2][gap3];
    bool& in = in_mem[i][gap_front][gap2][gap3];
    if(not in) {
        if(i >= n) {
            ans = (n / 2) * 2 + gap_front + gap2 + 2 * gap3 == i ? 0 : -INF;
        } else if(i == 0) {
            ans = max({
                a[0] + opt(2, false, 0, 0),
                3 <= n + 1 ? a[0] + opt(3, false, 1, 0) : -INF,
                4 <= n + 1 ? a[0] + opt(4, false, 0, 1) : -INF,
                1 < n ? a[1] + opt(3, true, 0, 0) : -INF,
                2 < n ? a[2] + opt(4, true, 1, 0) : -INF,
                3 < n ? a[3] + opt(5, true, 0, 1) : -INF
            });
        } else {
            ans = max({
                a[i] + opt(i + 2, gap_front, gap2, gap3),
                i + 3 <= n + 1 and gap2 < 2 ? a[i] + opt(i + 3, gap_front, gap2 + 1, gap3) : -INF,
                i + 4 <= n + 1 and gap3 < 2 ? a[i] + opt(i + 4, gap_front, gap2, gap3 + 1) : -INF,
                i + 1 < n and gap2 < 2 ? a[i + 1] + opt(i + 3, gap_front, gap2 + 1, gap3) : -INF,
                i + 2 < n and gap3 < 2 ? a[i + 2] + opt(i + 4, gap_front, gap2, gap3 + 1) : -INF
            });
        }
        in = true;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << opt(0, 0, 0, 0) << endl;
    return 0;
}
