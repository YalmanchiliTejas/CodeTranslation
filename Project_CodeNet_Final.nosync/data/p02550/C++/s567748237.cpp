#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> S;
    S.insert(X);
    ll sum1 = X;
    N--;
    vector<ll> V, W; // value, accumulate
    W.push_back(0);
    V.push_back(X); W.push_back(0 + X);
    while (1) {
        X = X * X % M;
        if (S.count(X) > 0) break;
        S.insert(X);
        sum1 += X;
        V.push_back(X);
        W.push_back(W.back() + X);
        N--;
        if (N == 0) {
            cout << sum1 << endl;
            return 0;
        }
    }
    auto p = find(V.begin(), V.end(), X);
    auto n = distance(V.begin(), p);
    ll n2 = V.size() - n; // N already subbed 1 loop times
//    cout << W[n] + (W.back() - W[n]) * (N / n2) + W[n + N % n2] - W[n] << endl;
    cout << (W.back() - W[n]) * ((N + n2) / n2) + W[n + (N + n2) % n2] << endl;

}
