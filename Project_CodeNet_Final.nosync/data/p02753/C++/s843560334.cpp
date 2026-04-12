#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define int long long
#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 2e9;
const int MB = 20;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    set<char> st;
    for (char c : s) st.insert(c);
    cout << (st.size() == 1 ? "No" : "Yes");
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}