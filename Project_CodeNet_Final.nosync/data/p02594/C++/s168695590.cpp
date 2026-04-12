#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
// -2.1e-9 <= int <= 2.1e9
// -9.2e-18 <= long long <= 9.2e18
// 0 <= unsigned int <= 4.2e9
// 0 <= unsigned long long <= 18.4e18
// cout << fixed << setprecision(10);

int main() {
    int X;
    cin >> X;
    if(X >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
