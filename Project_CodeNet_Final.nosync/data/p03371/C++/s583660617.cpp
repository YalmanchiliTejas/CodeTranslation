#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    uint32_t ans = UINT32_MAX;
    if(a / 2 + b / 2 < c){
        cout << a * x + b * y << endl;
        return 0;
    } else {
        for (auto i = 0; i <= max(x, y) * 2; i++) {
            uint32_t tmp = c * i + a * max((x - i / 2), 0) + b * max((y - i / 2), 0);
            if(tmp < ans) ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}