#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int r, g, b, n;
    cin >> r >> g >> b;
    n = r * 100 + g * 10 + b;
    if (n % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
