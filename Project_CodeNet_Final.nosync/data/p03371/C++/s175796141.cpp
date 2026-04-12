#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll res = 1e18;
    for (int i = 0; i <= (int)1e5; i++) {
        res = min(res, 1LL*(i*2*c)+(max(0, x-i) * a)+(max(0, y-i) * b));
    }
    cout << res << endl;
}
