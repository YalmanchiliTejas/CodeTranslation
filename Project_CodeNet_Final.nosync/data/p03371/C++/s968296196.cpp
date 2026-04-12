#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    ll price = 1e9;
    for (int c=2*max(X,Y);c>=0;c--){
        int a = max(X-(c/2),0);
        int b = max(Y-(c/2),0);
        price = min(price,ll(A*a+B*b+C*c));
    }
    cout << price << endl;
    return 0;
}