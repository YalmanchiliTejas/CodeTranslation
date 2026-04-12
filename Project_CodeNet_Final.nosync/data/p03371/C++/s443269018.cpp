#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int A,B,C,x,y; cin >> A >> B>> C >> x >> y;
    ll res = 1e9;
    for (int c=0;c<=2*max(x,y);c++){
        int a = max(0,x - c/2);
        int b = max(0,y - c/2);
        res = min(ll(A*a+B*b+C*c),res);
    }
    cout << res << endl;
    return 0;
}