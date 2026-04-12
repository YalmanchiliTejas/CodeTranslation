#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a * x + b * y;
    if(x < y){
        ans = min(ans, c * (2 * x) + b * (y - x));
        ans = min(ans, c * (2 * y));
    } else {
        ans = min(ans, c * (2 * y) + a * (x - y));
        ans = min(ans, c * (2 * x));
    }
    cout << ans << endl;
    return 0;
}