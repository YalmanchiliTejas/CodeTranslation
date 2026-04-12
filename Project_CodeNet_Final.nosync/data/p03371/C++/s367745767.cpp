// 「A1枚+B1枚」セットが残っているとき、
// AとBを別々で買うのと、ABを買うのとどちらが安いかを検討する
// それが終わった時、
// 残ったA or B1枚を買うのと、 AB2枚を買うのとどちらが安いかを検討する

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_L = 100000;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    ll set_min = min(X, Y);

    ans += set_min * min(A + B, 2 * C);

    if (X - set_min > 0) {
        ans += (X - set_min) * min(A, 2 * C);
    }
    if (Y - set_min > 0) {
        ans += (Y - set_min) * min(B, 2 * C);
    }

    cout << ans << endl;

    return 0;
}