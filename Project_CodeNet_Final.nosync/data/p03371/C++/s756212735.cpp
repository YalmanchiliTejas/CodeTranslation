#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(x) cout << x << endl;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int z = 0;
    int ab = a + b;
    int ans = a * x + b * y;
    // AB2枚の方が安い場合
    if(ab > c * 2){
        int m = max(x, y);
        for(int i = m * 2; 0 < i; i-=2){
            z = i / 2;
            int rx = 0;
            int ry = 0;
            if(0 <= x - z){ rx = x - z; }
            if(0 <= y - z){ ry = y - z; }
            int sum = rx * a + ry * b + i * c;
            ans = min(ans, sum);
        }
    }
    OP(ans);
}
