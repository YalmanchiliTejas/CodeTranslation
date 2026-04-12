#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define rep(i,n) for(long long  i = 0; i < n; i++)
#define rep2(i,a,n) for(long long  i = a; i < n; i++)
#define in(a) cin >> a
#define out(a) cout << a << endl
typedef long long ll;

using namespace std;

int main() 
{
    ll a,b,c,x,y;
    ll ans = INF;
    cin >> a >> b >> c >> x >> y;

    for(ll i = 1; i <= x; i++) {
        ans = min(ans, i * a + (x-i)*2*c + max(y-(x-i), (ll)0) * b);        
    }

    for(ll i = 1; i <= y; i++) {
        ans = min(ans, i * b + (y-i)*2*c + max(x-(y-i), (ll)0) * a);        
    }

    for(ll i = 1; i <= x; i++) {
        ans = min(ans, i*2*c + (x-i)*a + max(y-i, (ll)0) * b);        
    }

    for(ll i = 1; i <= y; i++) {
        ans = min(ans, i*2*c + (y-i)*b + max(x-i, (ll)0) * a);        
    }

    cout << ans << endl;

    return 0;
}
