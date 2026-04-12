#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(a) cout << (a) << endl;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for( int i = 0; i < n; i++ ) cin >> a[i];
    sort( a.begin(), a.end() );
    ll s, t;
    s = t = 0;
    for( int i = 0; i < n/2; i++ ) s += a[i]*2;
    for( int i = n/2; i < n; i++ ) t += a[i]*2;
    ll res;
    if( n%2 == 0 ) {
        res = (t-a[n/2])-(s-a[n/2-1]);
    }
    else {
        ll sum1, sum2;
        sum1 = sum2 = 0;
        sum1 = (t-a[n/2]-a[n/2+1]) - s;
        sum2 = (t-a[n/2]*2) - (s+a[n/2]-a[n/2-1]);
        res = max( sum1, sum2 );
    }
    dump( res );
    return 0;  
}