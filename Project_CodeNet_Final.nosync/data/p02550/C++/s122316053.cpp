#include <iostream>
using namespace std;

int main() {
    long n, x, m;
    cin >> n >> x >> m;
    long res = 0;
    long i, j = x, k = x, l, c = 0;
    while (true) {
        j = j * j % m;
        k = k * k % m;
        k = k * k % m;
        if (j == k) {
            l = x;
            while(l != j) {
                c++;
                j = j * j % m;
                l = l * l % m;
            }
            break;
        }
    }
    j = x;
    if (n <= c) {
        for (i = 0; i < n; i++) {
            res += j;
            j = j * j % m;
        }
        cout << res << endl;
        return 0;
    }
    for (i = 0; i < c; i++) {
        res += j;
        j = j * j % m;
    }
    n -= c;
    long r = 0, rc = 0;
    k = j;
    do {
        r += k;
        k = k * k % m;
        rc++;
    }while(k != j);
    res += r * (n / rc);
    for (i = 0; i < (n % rc); i++) {
        res += j;
        j = j * j % m;
    }
    cout << res << endl;
}
