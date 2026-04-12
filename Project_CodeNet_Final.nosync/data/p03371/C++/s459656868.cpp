#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll out = 0;
    ll less = min(X,Y);
    if((A+B)>2*C){
        out = C*2*less;
        if(X>Y) out += min(A,C*2)*(X-less);
        else out += min(B,C*2)*(Y-less);
    }else out = A*X+B*Y;
    cout << out << endl;
    return 0;
}
