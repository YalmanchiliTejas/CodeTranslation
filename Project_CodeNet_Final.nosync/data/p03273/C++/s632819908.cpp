#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];
    set<int> allwhite_i, allwhite_j;
    rep(i, h) {
        bool flag = true;
        rep(j, w) {
            if (a[i][j] == '#') flag = false;
        }
        if (flag) allwhite_i.insert(i);
    }
    rep(j, w) {
        bool flag = true;
        rep(i, h) {
            if (a[i][j] == '#') flag = false;
        }
        if (flag) allwhite_j.insert(j);
    }
    rep(i, h) {
        if (allwhite_i.count(i)) continue;
        rep(j, w) {
            if (!allwhite_j.count(j))cout << a[i][j];
        }
        cout << endl;
    }
}