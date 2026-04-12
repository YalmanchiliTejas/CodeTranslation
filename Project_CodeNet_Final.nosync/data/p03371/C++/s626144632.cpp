#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    ll a, b, c, x, y, ss, sss;
    cin >> a >> b >> c >> x >> y;
    ll d = (a * x);
    ll e = (b * y);
    ll s = d + e;
    if(x >= y) {
       ll p = x - y;
       ll q = (c * (y*2));
       ll k =  a * p;
       ss = (q + k);
       sss = (x * c * 2);
    }
    else {
       ll p = y - x;
       ll q = (c * (x*2));
       ll k =  b * p;
       ss = (q + k);
       sss= (y*c * 2);
    }
    cout << min(s, min(ss, sss)) << endl;
    return 0;
}
