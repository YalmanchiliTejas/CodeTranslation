#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int add(int a, int b) { a += b; return a < P ? a : a - P; }
int sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int mul(int a, int b) { return 1ll * a * b % P; }
int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

int main(void) {
    int n; scanf("%d", &n);
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        s1 = add(s1, x);
        s2 = add(s2, mul(x, x));
    }
    printf("%d\n", mul(sub(mul(s1, s1), s2), (P + 1) / 2));

    return 0;
}