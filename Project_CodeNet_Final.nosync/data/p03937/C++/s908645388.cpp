#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }
    vector<int> route;
    for (int i = 0; i < H; i++) {
        int right = -1;
        int left = W;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                if (j < left) left = j;
                right = j;
            }
        }
        if (i != 0 && left != route[i - 1]) {
            cout << "Impossible" << endl;
            return 0;
        }
        route.push_back(right);
    }
    cout << "Possible" << endl;

    return 0;
}
