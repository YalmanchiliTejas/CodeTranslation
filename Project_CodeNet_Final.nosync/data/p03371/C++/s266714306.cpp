#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    while(1) {
        if ( x <= 0 && y <= 0 ) break;
        if ( x > 0 && y > 0 ) {
            if ( a + b > c * 2 ) {
                ans += c * 2;
                --x;
                --y;
            }
            else if ( a > c * 2 ) {
                ans += c + 2;
                --x;
                --y;
                if ( y > 0 ) {
                    ans += b;
                    --y;
                }
            }
            else if ( b > c * 2 ) {
                ans += c * 2;
                --x;
                --y;
                if ( x > 0 ) {
                    ans += a;
                    --x;
                }
            }
            else {
                ans += a + b;
                --x;
                --y;
            }
        }
        else if ( x <= 0 ) {
            if ( b > c * 2 ) {
                ans += c * 2;
                --x;
                --y;
            }
            else {
                ans += b;
                --y;
            }
        }
        else {
            if ( a > c * 2 ) {
                ans += c * 2;
                --x;
                --y;
            }
            else {
                ans += a;
                --x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
