#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1LL<<60;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int a, b, c, x, y;

int main() {
    cin >> a >> b >> c >> x >> y;
    int ans = INT_INF;
    // ABピザをi枚買う
    for (int i = 0; i <= 2 * max(x, y); i++) {
        int tmp = 2 * c * i + a * max(0, x - i) + b * max(0, y - i);
        if (tmp < ans) ans = tmp;
    }
    cout << ans << endl;
}
