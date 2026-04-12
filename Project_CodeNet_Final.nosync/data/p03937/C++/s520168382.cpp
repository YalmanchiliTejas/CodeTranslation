#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <type_traits>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int h, w; cin >> h >> w;
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c; cin >> c;
            if(c == '#') cnt++;
        }
    }

    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
    return 0;
}
