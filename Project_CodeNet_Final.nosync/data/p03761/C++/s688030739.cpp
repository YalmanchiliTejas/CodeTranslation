#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF INT32_MAX / 2
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
//#define int long long

signed main() {
    int n;
    cin >> n;
    map<char, int> m;
    map<char, int> ans;
    rep(i, 26) ans['a' + i] = 100;
    string s;
    rep(i, n) {
        cin >> s;
        rep(j, int(s.size())) m[s[j]]++;
        rep(j, 26) chmin(ans['a' + j], m['a' + j]);
        m.clear();
    }
    string res = "";
    rep(i, 26) {
        if (ans['a' + i] == 100)
            continue;
        else {
            while (ans['a' + i]--)
                res.push_back('a' + i);
        }
    }
    cout << res << endl;
    return 0;
}