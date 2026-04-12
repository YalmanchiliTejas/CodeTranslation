#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> Len(51);
vector<ll> Pat(51);

ll rec(ll n, ll x) {
    if (x == 0) return 0;
    if (x == Len[n]) return Pat[n];

    if (x > 0) x--;  //パンが1枚減る
    if (x <= Len[n - 1]) {
        return rec(n - 1, x);
    }
    x -= Len[n - 1];
    if (x > 0) x--;  // ここでパティが1増える
    if (x <= Len[n - 1]) {
        return (ll)1 + Pat[n - 1] + rec(n - 1, x);
    }
    return Pat[n];
}

int main() {
    ll N, X;
    cin >> N >> X;
    Len[0] = 1;
    Pat[0] = 1;

    for (int i = 1; i <= N; i++) {
        Len[i] = 1LL + Len[i - 1] + 1 + Len[i - 1] + 1;
        Pat[i] = 2 * Pat[i - 1] + 1LL;
    }

    cout << rec(N, X) << endl;
}