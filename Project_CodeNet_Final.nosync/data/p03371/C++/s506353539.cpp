#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define rep(i, n) for(int (i) = (0); (i) < (n); (i++))
using ll = long long;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;

    // aとbを直接買ったときのお金
    int abpizza = (a * x) + (b * y);

    // cだけを買った時の金額
    int cpizza = c * std::max(x, y) * 2;

    int xymin = std::min(x, y);
    int x2 = x - xymin;
    int y2 = y - xymin;
    int abcpizza = a * x2 + b * y2 + c * (xymin * 2);
    
    ans = std::min(abpizza, std::min(cpizza, abcpizza));

    cout << ans << endl;
}