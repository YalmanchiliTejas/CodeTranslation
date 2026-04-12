#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    ll cnts = min(X, Y);
    ll cntb = max(X, Y) - cnts;
    ans = min(cnts * C * 2, (A + B) * cnts);
    if (X > Y) {
        ans += min((C * 2) * cntb, A * cntb);
    }
    else {
        ans += min((C * 2) * cntb, B * cntb);
    }

    cout << ans << endl;
    return 0;
}