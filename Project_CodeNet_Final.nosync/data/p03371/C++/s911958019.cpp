#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long int ans = 0;
    if(a + b <= 2 * c) ans = a * x + b * y;
    if(a + b >  2 * c){
        ans = 2 * c * min(x, y)
            + min(a, 2 * c) * (x - min(x,y))
            + min(b, 2 * c) * (y - min(x,y));
    }
    cout << ans << endl;
    return 0;
}