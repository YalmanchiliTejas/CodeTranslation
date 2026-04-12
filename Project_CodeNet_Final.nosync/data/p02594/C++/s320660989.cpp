#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template <class T>
void read(T& x, T f = 1, char ch = getchar()) {
    x = 0;
    while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    x *= f;
}
int n;
int main() {
    cin >> n;
    if (n >= 30)
        puts("Yes");
    else
        puts("No");
    return 0;
}
