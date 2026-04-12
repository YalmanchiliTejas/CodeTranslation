#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, x, y;
    long long int ans = 0;

    cin >> a >> b >> c >> x >> y;

    if (a + b > c * 2) {
        ans += c*2*min(x, y);
        if (x > y) {
            if (a > c*2) {
                ans += (x-y)*c*2;
            }
            else {
                ans += (x-y)*a;
            }
        }
        else if (x < y) {
            if (b > c*2) {
                ans += (y-x)*c*2;
            }
            else {
                ans += (y-x)*b;
            }
        }
    }
    else {
        ans += a * x + b * y;
    }

    cout << ans << endl;
}
