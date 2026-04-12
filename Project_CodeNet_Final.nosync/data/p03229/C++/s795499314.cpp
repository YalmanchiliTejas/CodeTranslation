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

ll get(vll& b) {
    ll sm = 0;
    rep(i, sz(b) - 1) {
        sm += abs(b[i+1] - b[i]);
    }
    return sm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = -1;
    vll b(n);
    if (n % 2 == 0) {
        //　大小......大小
        rep(i, n/2) b[2*i + 1] = a[i];
        rep(i, n/2) b[2*i] = a[i+n/2];
        ans = get(b);
    } else {
        // 大小......小大
        rep(i, n/2) b[2*i + 1] = a[i];
        b[n-1] = a[n/2];
        rep(i, n/2) b[2*i] = a[n/2+1+i];
        chmax(ans, get(b));
        // 小大......大小
        rep(i, n/2) b[2*(i+1)] = a[i];
        b[0] = a[n/2];
        rep(i, n/2) b[2*i + 1] = a[n/2+1+i];
        chmax(ans, get(b));
    }
    cout << ans << endl;
}