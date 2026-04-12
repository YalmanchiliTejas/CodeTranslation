#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

const int N = 200005;
int ara[N];

int main( )
{
    int n, i, j, k;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    if (n % 2) {
        i = n;
        int fl = 0;
        while (i > 0) {
            if (fl) cout << ' ';
            cout << ara[i];
            fl = 1;
            i -= 2;
        }
        i = 2;
        while (i < n) {
            if (fl) cout << ' ';
            cout << ara[i];
            i += 2;
            fl = 1;
        }
    }
    else {
        i = n;
        int fl = 0;
        while (i > 0) {
            if (fl) cout << ' ';
            cout << ara[i];
            fl = 1;
            i -= 2;
        }
        i = 1;
        while (i < n) {
            if (fl) cout << ' ';
            cout << ara[i];
            i += 2;
            fl = 1;
        }
    }
    cout << '\n';
    return 0;
}

