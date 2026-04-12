#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main()
{
    int r, g, b, sum;
    cin >> r >> g >> b;

    sum = r * 100 + g * 10 + b;

    if (sum % 4 == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        cout << "NO" << endl;
        return 0;
    }
}