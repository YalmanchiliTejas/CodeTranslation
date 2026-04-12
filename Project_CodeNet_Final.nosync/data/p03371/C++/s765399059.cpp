#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll d1 = x * a + y * b;
    ll d2 = 2 * c * max(x, y);
    ll d3;
    if(x > y) d3 = 2 * c * y + a * (x - y);
    else d3  = 2 * c * x + b * (y - x);
    cout << min({d1, d2, d3}) << endl;
    return 0;
}