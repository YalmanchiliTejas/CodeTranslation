#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll a,b,c,x,y;
    ll ans = 5000 * 100000 * 2;
    cin >> a >> b >> c >> x >> y;

    // ABピザをiまい買う
    for(ll i = 0; i /2 <= x || i / 2 <= y; i+=2 ){
        ll tmpans = c * i;

        // 残りの買う量
        ll tmp_a = x - i/2;
        ll tmp_b = y - i/2;
        // 残りが必要なら買う
        if(tmp_a >= 0) tmpans += a * tmp_a;
        if(tmp_b >= 0) tmpans += b * tmp_b;

        if(tmpans < ans) ans = tmpans;

    }
    cout << ans << endl;

}
