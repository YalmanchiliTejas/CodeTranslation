#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 1e9 + 7;
    ll total = 0;
    for(int i = 0; i <= max(x, y); i++){
        total = 2*i*c + max(0, x-i) * a + max(0, y-i) * b;
        if(ans > total){
            ans = total;
        }
    }

    cout << ans << endl;

    return 0;
}