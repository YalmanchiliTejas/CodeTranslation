#include <bits/stdc++.h>
using namespace std;

int main () {
    int r, g, b, x;
    cin >> r >> g >> b;
    x = r * 100 + g * 10 + b;
    printf(x % 4 == 0 ? "YES" :"NO");
}