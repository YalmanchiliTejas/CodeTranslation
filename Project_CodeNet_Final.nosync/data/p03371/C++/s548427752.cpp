#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<typename T> void view(T cont) {std::cout << cont << std::endl;}
template<typename T> void view(T* cont, ll sz) {rep(i, sz) std::cout << cont[i] << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<T>& v) {for (const auto& f: v) std::cout << f << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v: vv) {view(v);}}
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    int ans = 1e9;
    for (int n = 0; n <= 2 * max(X, Y); n += 2) {
        int temp = A * max(0, X - n / 2) + B * max(0, Y - n / 2) + C * n;
        if (temp < ans) ans = temp;
    }
    cout << ans << endl;
}