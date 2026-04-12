#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define REP(i, n) for(int i(0); i<(int)(n);i++)

int n, h, mh = -1, ans = 0;

int main() {
    cin >> n;
    REP(i, n) {
        cin >> h;
        ans += h >= mh;
        mh = max(mh, h);
    }
    cout << ans << endl;
    return 0;
}