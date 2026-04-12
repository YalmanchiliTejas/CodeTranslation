#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    ll a,b,c,x,y;
    ll mx,p,m = 10e9;
    cin >> a >> b >> c >> x >> y;
    mx = max(x,y);
    for(ll i = 0; i/2 <= mx; i += 2) {
        p = i * c;
        p += (i/2 < x) ? (x - i/2) * a:0;
        p += (i/2 < y) ? (y - i/2) * b:0;
        m = min(m,p);
    }
    cout << m << endl;
}
