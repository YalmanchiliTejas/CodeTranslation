#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

vector<ll> num;

vector<map<ll, pair<bool, ll>>> memo;

ll f(ll l, ll n) {
    if (n <= 0) {
        return 0;
    }
    if (l == 0) {
        return 1;
    }

    auto& curr = memo[l][n];
    if (curr.first) {
        return curr.second;
    }
    curr.first = true;

    ll result = 0;

    //B
    n--;

    //L-1バーガー
    result += f(l - 1, min(n, num[l - 1]));
    n -= num[l - 1];

    //P
    if (n-- >= 1) {
        result++;
    }

    //L-1バーガー
    result += f(l - 1, min(n, num[l - 1]));
    n -= num[l - 1];

    //B
    n--;

    return curr.second = result;
}

int main() {
    ll N, X;
    cin >> N >> X;

    num.resize(N, 1);
    for (ll i = 1; i < N; i++) {
        num[i] = 2 * num[i - 1] + 3;
    }

    memo.resize(N + 1);

    cout << f(N, X) << endl;
}