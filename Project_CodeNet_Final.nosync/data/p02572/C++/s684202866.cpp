// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
constexpr int MOD = 1000000000 + 7;

// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b
// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const int sum = accumulate(a.begin(), a.end(), 0LL);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[i] % MOD * ((sum - a[i]) % MOD);
        ans %= MOD;
    }

    ans %= MOD;
    ans = ans * modinv(2, MOD) % MOD;

    cout << ans << endl;
}

// hint
// https://www.wolframalpha.com/input/?i=a(b%2Bc%2Bd)+%2Bb(a%2Bc%2Bd)+%2B+c(a%2Bb%2Bd)+%2B+d(a%2Bb%2Bc)&lang=ja
