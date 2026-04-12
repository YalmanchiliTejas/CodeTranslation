/*
    Problem 5
    https://atcoder.jp/contests/abc095/tasks/arc096_a
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = INF;
    for (int i = 0; i <= max(x, y); i++) {
        // 全探索
        // 2 * i枚 C-pizza
        // x - i枚 A-pizza
        // y - i枚 B-pizza
        int sum = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}