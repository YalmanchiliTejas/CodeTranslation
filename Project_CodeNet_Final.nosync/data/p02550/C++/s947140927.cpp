#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> to(m);
    rep(i, m) {
        to[i] = ((ll)i * i) % m;
    }
    deque<ll> a; // 繰り返しの部分
    vector<bool> seen(m, false); // 一度見たかどうか
    ll k = n;
    ll cur = x;
    ll lead = 0;
    ll leadnum = 0;
    ll period = 0;
    while (true) {
        // 一度通った頂点を見つけたときの処理
        if (seen[cur]) {
            while (a[0] != cur) {
                // 最初の余計な数手分を除去する
                --k;
                lead += a[0];
                leadnum++;
                a.pop_front();
                // 繰り返す前に K が限界になったらリターン
                if (k == 0) {
                    cout << lead << endl;
                    return 0;
                }
            }
            break;
        }
        // 最初は愚直にシミュレーションしつつ、履歴をメモしていく
        a.push_back(cur);
        seen[cur] = true;
        cur = to[cur];
        period++;
    }
    k = period - leadnum;
    ll sum1 = 0;
    for (auto t: a) {
        sum1 += t;
    }
    ll last = 0;
    ll cnt = (n-leadnum) % k;
    rep(i, cnt) {
        last += a[i];
    }
    cout << lead + (n-leadnum)/k * sum1 + last << endl;
    return 0;
}
/*
g++ -std=c++17 -Wall -Wextra -g -O0 -fsanitize=undefined,address main.cpp && oj t
*/