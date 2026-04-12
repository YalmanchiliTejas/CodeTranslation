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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    cin >> h;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        ans += h[i] >= *max_element(h.begin(), h.begin() + i);
    }
    cout << ans << endl;
    return 0;
}
