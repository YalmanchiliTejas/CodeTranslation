#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1<<30;
    
    rep(i, (x>y? x+1: y+1)){
        ll sum = 0;
        sum += c*i*2;
        if(x-i>0)sum += a*(x-i);
        if(y-i>0)sum += b*(y-i);
        if(sum < ans){
            ans = sum;
        }
    }
    cout << ans << endl;
}