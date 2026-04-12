#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    ll H[N];
    rep(i,N) cin >> H[i];
    ll out = 1;
    rep(i,N){
        rep(j,i){
            if(H[j]>H[i]) break;
            if(j==i-1) out++;
        }
    }
    cout << out << endl;
    return 0;
}
