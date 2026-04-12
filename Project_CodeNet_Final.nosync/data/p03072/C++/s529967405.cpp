#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int h[100];
    cin >> n;
    int hmax = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (hmax <= h[i]) {
            hmax = h[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
