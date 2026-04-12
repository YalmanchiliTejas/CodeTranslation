#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = min(a*x + b*y, max(x, y)*c*2);
    if(x < y) ans = min(ans, x*c*2+(y-x)*b);
    else ans = min(ans, y*c*2+(x-y)*a);
    cout << ans << endl;
}

