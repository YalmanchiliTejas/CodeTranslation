#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    ll ans = 0;
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll mi = 10000000000000;
    for(int i = 0; i <= max(x, y); i++){
        ans = i * 2 * c;
        if(x - i > 0){
            ans += (x - i) * a;
        }
        if(y - i > 0){
            ans += (y - i) * b;
        }
        mi = min(mi, ans);
    }

    cout << mi << endl;
    return 0;
}
