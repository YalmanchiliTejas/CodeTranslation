#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    cout << min({a*x + b*y, c * 2 * x + (y - x > 0 ? b * (y-x):0), (x-y>0?a * (x-y):0) + c * 2 * y}) << endl;

    return 0;
}