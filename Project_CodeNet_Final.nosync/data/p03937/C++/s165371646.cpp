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
    vector<vector<char>> a(h, vector<char> (w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    int right = 0;
    for(int i = 0; i < h; i++) {
        bool flag = true;
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '#') {
                if(flag && j != right) {
                    cout << "Impossible" << endl;
                    return 0;
                } else if(!flag && j < right){
                  cout << "Impossible" << endl;
                  return 0;
                } else {
                    right = j;
                    flag = false;
                }
            }
        }
    }

    cout << "Possible" << endl;
    return 0;
}
