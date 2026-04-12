#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
using llong = long long;

llong n;
llong sum;
llong m;

int main() {

    while (scanf("%lld", &n), n != 0) {
        llong minv = 1ll << 60ll;
        llong maxv = -1;
        sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> m;

            sum += m;

            minv = min(minv, m);
            maxv = max(maxv, m);
        }

        cout << (sum - maxv - minv) / (n - 2) << endl;
    };

    return 0;
}

