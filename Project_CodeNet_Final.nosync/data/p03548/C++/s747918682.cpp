#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <unordered_map>

#define div 1000000000+7

using ll = long long;
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    x = x - z;
    cout << x/(y+z) << endl;
}

int main() {
    solve();
    return 0;
}