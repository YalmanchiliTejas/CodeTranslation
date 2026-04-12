#include <bits/stdc++.h>
using namespace std;  

int main() {
    int a, b, c, x, y, ans;
    cin >> a >> b >> c >> x >> y;
    
    ans = a*x + b*y;
    ans = min(ans, c*x*2 + b * max(y-x, 0));
    ans = min(ans, c*y*2 + a * max(x-y, 0));
    
    cout << ans << endl;
    
    return (0);
}
