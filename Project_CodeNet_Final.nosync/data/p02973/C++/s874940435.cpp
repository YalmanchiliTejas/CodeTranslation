#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b;
    rep(i, n) {
        // にぶたん
        // その数字より小さい最大の数字の値をその数字で書き換える
        if (b.empty()) {b.push_back(a[i]); continue;}
        auto it = lower_bound(all(b), a[i]);
        // いままでの最大値が出た場合
        if (it==b.end()) b.back()=a[i];
        // いままでの最小値が出た場合
        else if (it==b.begin() && *it>=a[i]) b.insert(b.begin(), a[i]);
        else *(it-1) = a[i];
        debug(i, b);
    }
    cout << sz(b) << endl;
}