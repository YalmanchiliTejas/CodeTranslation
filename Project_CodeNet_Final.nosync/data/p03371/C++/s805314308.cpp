#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll s = a*x + b*y;
    ll t = 2*c*min(x,y) + a*(x-min(x,y)) + b*(y-min(x,y));
    ll u = 2*max(x,y)*c;
    cout << min(s,min(t,u)) << endl;
    return 0;
}