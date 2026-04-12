#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // Aiの値は周期性がありそう、M < 10^5
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> st;
    vector<ll> A;
    A.push_back(X);
    while (1) {
        X = X * X % M;
        if (st.find(X) != st.end()) break;
        A.push_back(X);
        st.insert(X);
    }
    ll ind = find(A.begin(), A.end(), X) - A.begin();
    ll length = sz(A) - ind;
    ll ans = 0;
    ll time = (N - ind) / length;
    ll remain = (N - ind) % length;
    for (int i = 0; i < sz(A); i++) {
        if (i < ind) ans += A[i];
        else {
            if (i - ind < remain) ans += A[i];
            ans += A[i] * time;
        }
    }
    cout << ans << '\n';
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}