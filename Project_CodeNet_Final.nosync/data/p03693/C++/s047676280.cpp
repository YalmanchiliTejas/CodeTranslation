#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int r, g, b;
    cin >> r >> g >> b;
    (((r * 100 + g * 10 + b) % 4 == 0) ? puts("YES") : puts("NO"));
    return 0;
}