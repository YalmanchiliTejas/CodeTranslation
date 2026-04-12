#include <algorithm>
#include <iostream>
#include <string>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

// 158 - c
int main(void) {
    int a, b, c;
    int x, y;

    cin >> a >> b >> c >> x >> y;

    // int z = min(x, y) / 2;
    int z = max(x, y);

    int mVal = 5000 * 100000 * 2;
    int aCnt, bCnt, cCnt;
    repe(_z, 0, z) {
        cCnt = 2 * _z;
        aCnt = x - _z;
      if(aCnt < 0) aCnt = 0;
        bCnt = y - _z;
      if(bCnt < 0) bCnt = 0;

        int tVal = a * aCnt + b * bCnt + c * cCnt;
        mVal = min(mVal, tVal);
    }

    cout << mVal << endl;

    return 0;
}