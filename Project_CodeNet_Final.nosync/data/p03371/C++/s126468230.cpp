#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans1 = max(x, y) * 2 * c;
    ll ans2 = a * x + b * y;
    ll ans3;
    if(x < y) ans3 = c * 2 * x + b * (y - x);
    else ans3 = c * 2 * y + a * (x - y);
    cout << min({ans1, ans2, ans3}) << endl;
    return 0;
}