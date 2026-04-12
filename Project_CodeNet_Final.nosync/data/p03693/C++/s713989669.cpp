#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << ((100 * r + 10 * g + b) % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}