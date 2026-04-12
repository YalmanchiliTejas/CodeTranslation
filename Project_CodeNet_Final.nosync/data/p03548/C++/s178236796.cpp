#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>

#define p(a, b) pair<a, b>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    y += z;
    cout << x/y;
    return 0;
}
