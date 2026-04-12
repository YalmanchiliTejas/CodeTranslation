#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    int a, b, c, x, y;
    int ans = 0;
    cin >> a >> b >> c >> x >> y;
    ans = a*x + b*y;
    if (x > y) {
        ans = min(2*y*c + a*(x - y), ans);
        ans = min(ans, 2*x*c);
        cout << ans << endl;
        return 0;
    } else {
        ans = min(2*x*c + b*(y - x), ans);
        ans = min(ans, 2*y*c);
        cout << ans << endl;
        return 0;
    }
}