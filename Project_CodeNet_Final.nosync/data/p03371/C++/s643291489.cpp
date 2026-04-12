// https://qiita.com/e869120/items/eb50fdaece12be418faa
// https://atcoder.jp/contests/abc095/tasks/arc096_a
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;

const int INF = 1e9 + 7;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int n = max(X, Y);

    int res = INF;
    for (int i = 0; i <= 2 * n; i+=2) {
        int sum = i * C + A * max(0, X - i / 2) + B * max(0, Y - i / 2);
        res = min(res, sum);
    }

    cout << res << endl;

    return 0;
}