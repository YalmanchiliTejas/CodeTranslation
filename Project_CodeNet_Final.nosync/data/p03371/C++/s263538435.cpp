/*
    Problem 5
    https://atcoder.jp/contests/abc095/tasks/arc096_a
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;
/* typedef */
typedef long long ll;
/* constant */
const ll MAX = 100000000000;
/* global variables */
/* function */
/* main */
int main(){
    ll A, B, C, X, Y;
    cin >>  A >> B >> C >> X >> Y;
    ll ans = MAX;

    ans = min(ans, C * max(X, Y) * 2);
    ans = min(ans, A * X + B * Y);
    ans = min(ans, C * X * 2 + B * ((Y - X > 0) ? Y - X : 0));
    ans = min(ans, C * Y * 2 + A * ((X - Y > 0) ? X - Y : 0));

    cout << ans << '\n';
}
