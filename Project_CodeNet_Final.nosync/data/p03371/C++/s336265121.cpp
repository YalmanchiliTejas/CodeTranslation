#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = a * x + b * y;
    ll ans1 = max(x, y) * 2 * c;
    ll ans2;
    if (x < y){
        ans2 = x * 2 * c + (y - x) * b;
    }
    else{
        ans2 = y * 2 * c + (x - y) * a;
    }

    cout << min(min(ans, ans1), ans2) << endl;
}
