#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if (a + b > 2 * c){
        ans += min(x, y) * 2 * c;
        ll xx = x;
        x -= min(x,y);
        y -= min(xx,y);
        if (x > 0){
            if (a > 2 * c){
                ans += x * 2 * c;
            }
            else {
                ans += x * a;
            }
        }
        else {
            if (b > 2 * c){
                ans += y * 2 * c;
            }
            else {
                ans += y * b;
            }
        }
    }
    else {
        ans += x * a + y * b;
    }
    cout << ans << endl; 
}