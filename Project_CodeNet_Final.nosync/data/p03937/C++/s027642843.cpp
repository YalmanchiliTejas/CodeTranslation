#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    int pass_num = 0;
    rep(i, h) rep(j, w) {
        char tmp;
        cin >> tmp;
        if (tmp == '#') ++pass_num;
    }
    if (pass_num == h + w - 1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}