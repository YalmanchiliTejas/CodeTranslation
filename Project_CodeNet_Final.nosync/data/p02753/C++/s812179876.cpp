#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
#define printd(x) printf("%.12f\n", ans);
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;
#define YES() cout << "YES" << endl;
#define NO() cout << "NO" << endl;
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main(void) {

    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No";
    }
    else cout << "Yes";
    
    return 0;
}
