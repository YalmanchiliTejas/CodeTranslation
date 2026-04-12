#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

ll f(ll A, ll M) {
    return (A * A) % M;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X, M;
    cin >> N >> X >> M;
    vector<bool> visited(M, false);
    --N;
    ll ans = X;
    // ループを求める
    ll A = f(X, M);
    while (!visited[A]) {
        visited[A] = true;
        A = f(A, M);
    }
    // Aまでの値を足す
    X = f(X, M);
    while (X != A) {
        if (N) {
            ans += X;
            --N;
        } else {
            cout << ans << endl;
            return 0;
        }
        X = f(X, M);
    }
    // ループ長と総和を求める
    ll len = 0;
    ll sum = 0;
    do {
        ++len;
        sum += X;
        X = f(X, M);
    } while (X != A);
    ans += sum * (N / len);
    N %= len;
    rep(i, 0, N) {
        ans += X;
        X = f(X, M);
    }
    cout << ans << endl;
    return 0;
}