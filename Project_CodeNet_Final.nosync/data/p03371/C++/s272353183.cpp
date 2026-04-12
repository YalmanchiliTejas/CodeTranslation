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

    for (ll i = 0; i <= X + Y; i++) {
        ll money = i * 2 * C + max(0LL, X - i) * A + max(0LL, Y - i) * B;
        ans = min(ans, money);
    }

    cout << ans << '\n';
}