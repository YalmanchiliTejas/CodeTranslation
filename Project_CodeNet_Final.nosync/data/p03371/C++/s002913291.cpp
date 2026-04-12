#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if ( a + b > c * 2 ) {
        ans += min(x, y) * c * 2 ; 
        int min_num = min(x,y);
        x -= min_num;
        y -= min_num;
//        cout << ans << " " << x << " " << y << endl;
        if ( x > 0 ) {
            if ( a > c * 2 ) {
                ans += x * c * 2;
            }
            else {
                ans += x * a;
            }
        }
        if ( y > 0 ) {
            if ( b > c * 2 ) {
                ans += y * c * 2;
            }
            else {
                ans += y * b;
            }
        }
    }
    else {
        ans = x * a + y * b;
    }
    cout << ans << endl;
    return 0;
}
