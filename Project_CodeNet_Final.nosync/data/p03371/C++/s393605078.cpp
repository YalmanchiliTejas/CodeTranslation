#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    long long res = 1000000000000000;
    long long cur = 0;
    int popular_pizza = max(X, Y);

    for (int i = 0; i <= popular_pizza; i++) {
        cur = i * 2 * C + A * max((X - i), 0) + B * max((Y-i), 0);
        if (res > cur) res = cur;
    }

    printf("%d\n", res);

    return 0;
}
