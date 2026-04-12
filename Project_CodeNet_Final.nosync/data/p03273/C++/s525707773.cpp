#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> a(h), b(w);
    vector<ll> c(h, 1), d(w, 1);
    rep1(i, h){
        cin >> a[i];
        if (a[i]==string(w, '.')) c[i] = 0;
        rep1(j, w){
            b[j] += a[i][j];
        }
    }
    rep1(i, w){
        if (b[i]==string(h, '.')) d[i] = 0;
    }
    rep1(i, h){
        rep1(j, w){
            if (c[i] && d[j]) cout << a[i][j];
        }
        if (c[i]) cout << endl;
    }
}