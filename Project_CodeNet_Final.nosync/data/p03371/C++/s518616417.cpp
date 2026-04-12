#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll p1 = max(x, y) * 2 * c;
    ll p2 = a * x + b * y;
    ll p3 = min(x, y) * 2 * c;
    if(x > y) p3 += (x - y) * a;
    else p3 += (y - x) * b;
    cout << min({p1, p2, p3}) << endl;
    return 0;
}