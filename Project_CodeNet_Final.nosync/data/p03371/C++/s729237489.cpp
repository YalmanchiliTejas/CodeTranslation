#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans;
    if (a+b <= 2*c) {
        ans = a*x + b*y;
    } else {
        int m = min(x,y);
        ans = 2*c*m;
        x -= m;
        y -= m;
        ans += min(a*x, 2*c*x);
        ans += min(b*y, 2*c*y);
    }
    cout << ans << endl;
    return 0;
}