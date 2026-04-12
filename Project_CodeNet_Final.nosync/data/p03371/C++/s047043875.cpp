#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace::std;
using ll = long long;
int main() {
    ll A,B,C,X,Y,a,b,c;
    cin >> A >> B >> C >> X >> Y;
    ll price = 1e15;
    for (ll c=2*max(X,Y);c>=0;c--){
        a = max({X-(c/2),ll(0)}); 
        b = max({Y-(c/2),ll(0)});
        ll tmp = A*a+B*b+C*c;
        price = min(tmp,price);
    }
    cout << price << endl;
    return 0;
}