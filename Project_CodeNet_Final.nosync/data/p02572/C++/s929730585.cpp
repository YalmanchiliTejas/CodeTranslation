#ifdef __GNUG__
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG // ArrayOutofBounds
#else
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#endif
#define rep(i, N) for (int i = 0; i < N; i++) //制御変数iを用いてN回転
using namespace std;
using ll = long long;
//0:上 1:左 2:下 3:右
const int di[] = { -1, 0, 1, 0};
const int dj[] = { 0, -1, 0, 1};

int main() {
    int N;
    const ll mod = 1000000007;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0, sum = 0;;
    for (int j = 1; j < N; j++) {
        sum += A[j - 1] % mod;
        sum %= mod;
        ans += (sum * A[j]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}