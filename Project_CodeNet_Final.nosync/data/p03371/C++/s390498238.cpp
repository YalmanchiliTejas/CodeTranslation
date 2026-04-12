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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A + B > C * 2) {
        int cnt = min(X, Y);
        X -= cnt; Y -= cnt;
        ans += cnt * C * 2;
        if (X > 0) {
            if (A > C * 2) {
                ans += C * 2 * X;
            }
            else {
                ans += A * X;
            }
        }
        if (Y > 0) {
            if (B > C * 2) {
                ans += C * 2 * Y;
            }
            else {
                ans += B * Y;
            }
        }
    }
    else {
        ans += A * X + B * Y;
    }

    cout << ans << endl;
    return 0;
}