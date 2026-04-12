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
ll greedy1(int n, vector<int>& x, vector<int>& y) {
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    int b1 = *min_element(I.begin(), I.end(), [&](int i, int j) {
        return make_pair(x[i], -y[i]) < make_pair(x[j], -y[j]);
    }), B_min = x[b1], R_min = y[b1];
    int b2 = *min_element(I.begin(), I.end(), [&](int i, int j) {
        return make_pair(y[i], -x[i]) > make_pair(y[j], -x[j]);
    }), B_max = x[b2], R_max = y[b2];
    for(int i : I) {
        if(i != b1 and i != b2) {
            B_max = max(B_max, x[i]);
            R_min = min(R_min, y[i]);
        }
    }
    return ll(R_max - R_min) * (B_max - B_min);
}
ll greedy2(int n, vector<int>& x, vector<int>& y) {
    int R_min = *min_element(x.begin(), x.end()), R_max = *max_element(y.begin(), y.end());
    vector<int> I, perm_B;
    for(int i = 0; i < n; i++) {
        if(x[i] == R_min) perm_B.push_back(y[i]);
        if(y[i] == R_max) perm_B.push_back(x[i]);
        if(x[i] != R_min and y[i] != R_max) {
            I.push_back(i);
        }
    }
    int perm_B_min = *min_element(perm_B.begin(), perm_B.end()), perm_B_max = *max_element(perm_B.begin(), perm_B.end());
    int y_min = lim<int>::max(), y_max = lim<int>::min();
    ll ans = lim<ll>::max();
    sort(I.begin(), I.end(), [&](int i, int j) { return make_pair(x[i], y[i]) < make_pair(x[j], y[j]); });
    for(int i = 0; i < I.size(); i++) {
        int B_min = min({y_min, x[I[i]], perm_B_min});
        int B_max = max({y_max, x[I.back()], perm_B_max});
        ans = min(ans, ll(R_max - R_min) * (B_max - B_min));
        y_min = min(y_min, y[I[i]]), y_max = max(y_max, y[I[i]]);
    }
    ans = min(ans, ll(R_max - R_min) * (max(y_max, perm_B_max) - min(y_min, perm_B_min)));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) {
            swap(x[i], y[i]);
        }
    }
    cout << min(greedy1(n, x, y), greedy2(n, x, y)) << endl;
    return 0;
}
