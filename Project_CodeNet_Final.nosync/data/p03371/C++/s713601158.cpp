#include <iostream>
typedef long long ll;
using namespace std;
int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;

    if(a+b<=c) {
        cout << a*x + b*y << endl;
        return 0;
    }

    ll min = a*x + b*y;
    for(ll i=0; i<200000; i++) {
        ll z = i*c + max(0LL, x-i)*a + max(0LL, y-i)*b;
        if(min>z) min=z;
    }
    cout << min << endl;;

    return 0;
}

