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
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<string> a(10);

int main(void) {
    int h, w;
    cin >> h >> w;
    rep (i, h) cin >> a[i];

    int cnt = 0;
    rep (i, h) rep (j, w) if (a[i][j] == '#') cnt++;

    
    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
    return 0;
}
