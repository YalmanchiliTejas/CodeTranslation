#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll d = 2 * c * min(x, y);
    if(x > y) d += a * (x - y);
    else d += b * (y - x);
    ll e = a * x + b * y;
    ll f = c * 2 * max(x, y);
    cout << min({d, e, f}) << endl;
    return 0;
}