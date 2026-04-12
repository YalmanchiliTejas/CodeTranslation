#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define dump(i) cout << "[*] " #i ": " << i << endl;
#else
#define dump(i)
#endif

long long int a[51];
long long int ha[51];

int main() {
    long long int x;
    int n;
    cin >> n >> x;

    a[0] = 1;
    ha[0] = 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] * 2 + 3;
        ha[i] = (a[i] + 1) / 2;
        dump(a[i]);
        dump(ha[i]);
    }
    long long int pnum = 0;
    while (n+1) {
        dump(n);
        dump(x);
        if (x == ha[n]) {
            pnum += ha[n-1] + 1;
            break;
        } else if (x == ha[n] - 1) {
            pnum += ha[n-1];
            break;
        } else if (x < ha[n] - 1) {
            x--;
            n--;
        } else if (x > ha[n]) {
            pnum += ha[n-1]+1;
            x -= ha[n];
            n--;
        }
    }

    cout << pnum << endl;
    return 0;
}
