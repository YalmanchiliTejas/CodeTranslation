#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
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

vll l(50), p(50);

ll f(int n, ll x) {
    if (n == 0) return 1;
    else if (x == 1) {
        return 0;
    } else if (x <= 1 + l[n-1]) {
        return f(n-1, x-1);
    } else if (x == 1 + l[n-1] + 1) {
        return p[n-1] + 1;
    } else if (x <= 1 + l[n-1] + 1 + l[n-1]) {
        return p[n-1] + 1 + f(n-1, x - (1 + l[n-1] + 1));
    } else {
        return p[n-1] + 1 + p[n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;
    rep(i, 50) {
        if (i == 0) {
            l[i] = 1;
            p[i] = 1;
        } else {
            l[i] = 2*l[i-1] + 3;
            p[i] = 2*p[i-1] + 1;
        } 
    }
    cout << f(n, x) << endl;
}