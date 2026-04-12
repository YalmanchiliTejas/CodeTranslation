#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = LONG_MAX;
    ll i = X;
    ll j = Y;
    ll k = 0;
    ll price;
    while(i >= 0 || j >= 0){
        if(i < 0) i = 0;
        if(j < 0) j = 0;
        price = A*i + B*j + C*k;
        ans = min(ans, price);
        i--;
        j--;
        k += 2;
    }
    cout << ans << endl;
}
