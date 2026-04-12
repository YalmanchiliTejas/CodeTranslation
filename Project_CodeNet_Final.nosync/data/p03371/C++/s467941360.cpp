/* 2020/03/17 Atcoder Beginner Contest 095 C - Half and Half */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    long long cbuy1, cbuy2, ans1 = 0, ans2 = 0, ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(a+b > c * 2) {
        cbuy1 = min(x, y);
        ans1 += c * cbuy1 * 2;
        ans1 += a * (x - cbuy1) + b * (y - cbuy1);
        cbuy2 = max(x, y);
        ans2 += c * cbuy2 * 2;
        ans = min(ans1, ans2);

    } else {
        ans += a * x + b * y;
    }
    cout << ans << endl;

    return 0;
}