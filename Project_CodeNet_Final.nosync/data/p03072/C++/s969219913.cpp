#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;

//const double PI = acos(-1);



int main() {
    int n, ans = 0, x, mx;
    cin >> n >> x;
    mx = x;
    ans++;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        if (x >= mx) {
            ans++;
            mx = x;
        }
    }
    cout << ans;
}

