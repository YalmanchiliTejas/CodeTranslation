#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fi first
#define se second
#define sqrt(x) sqrt(abs(x))
#define sqr(x) ((x) * (x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define fill(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb emplace_back
#define popcnt __builtin_popcount
#define ctz __builtin_ctz

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
istream& operator >> (istream &in, vector <T> &a) {
    for (T &i: a) in >> i;
    return in;
}

template <class T>
ostream& operator << (ostream &out, vector <T> &a) {
    for (T &i: a) out << i << ' ';
    return out;
}

template <class T>
ostream& operator << (ostream &out, set <T> &a) {
    for (auto &i: a) out << i << ' ';
    return out;
}

template <class T, class U>
istream& operator >> (istream &in, pair <T, U> &p) {
    in >> p.first >> p.second;
    return in;
}

template <class T, class U>
ostream& operator << (ostream &out, pair <T, U> &p) {
    out << p.first << ' ' << p.second;
    return out;
}

void fastIO() {
    ios_base:: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
}

string s;

signed main() {
    fastIO();

    cin >> s;
    string t = s;
    sort(all(s));
    sort(all(t), greater <char> ());

    if (s == t) cout << "No";
    else cout << "Yes";

    return 0;
}

/// ЗАПУСКАЕМ ГУСЯ:
/*
     ▄▀▀▀▄
▄███▀░◐░░░▌
    ▌░░░░░▐
    ▐░░░░░▐
    ▌░░░░░▐▄▄
    ▌░░░░▄▀▒▒▀▀▀▀▄
   ▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
   ▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
    ▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
      ▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
           ▌▌░▌▌
           ▌▌░▌▌
         ▄▄▌▌▄▌▌        */

