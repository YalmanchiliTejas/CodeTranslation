#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a>> b >> c >> x >> y;
    int ans;
    if(2 * c >= a + b){
        ans = x * a + y * b;
    }else{
        ans = min(2 * c * max(x, y), min(x, y) * c * 2 + abs(x - y) * ((y < x) ? a : b));
    }
    cout << ans << '\n';
    return 0;
}