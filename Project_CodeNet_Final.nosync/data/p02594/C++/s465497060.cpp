#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define $(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define x first
#define y second
#define int long long
#define double long double
#define pii pair<int, int>
#define pb push_back
#define vec vector
#define beg begin
#define dbg(x) cerr << #x << " = " << x << endl;

template<class T> ostream& operator<<(ostream &str, vector<T> &a) {
    for (auto &i : a) {
        str << i << " ";
    }
    return str;
}

template<class T> istream& operator>>(istream &str, vector<T> &a) {
    for (auto &i : a) {
        str >> i;
    }
    return str;
}

template<class T> ostream& operator<<(ostream &str, pair<T, T> &a) {
    str << a.first << " " << a.second;
    return str;
}

template<class T> istream& operator>>(istream &str, pair<T, T> &a) {
    str >> a.first >> a.second;
    return str;
}

void solve(); signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\artma\\CLionProjects\\problems\\input.txt", "r", stdin);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(6);
    solve();
    return 0;
}

const int MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e18 + 10, BASE = 37;

void solve() {
    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
