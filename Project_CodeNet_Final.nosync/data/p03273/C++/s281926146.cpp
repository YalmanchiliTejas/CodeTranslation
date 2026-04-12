#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    char m[h][w];
    bool height[h];
    bool width[w];
    for (int i = 0; i < h; i++) height[i] = false;
    for (int i = 0; i < w; i++) width[i] = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
            if (m[i][j] == '#') {
                height[i] = true;
                width[j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (height[i] && width[j]) cout << m[i][j];
        }
        if(height[i]) cout << endl;
    }
}
