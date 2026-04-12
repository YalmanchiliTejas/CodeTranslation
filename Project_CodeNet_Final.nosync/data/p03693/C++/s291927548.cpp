#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int ans = r * 100 + g * 10 + b;
    if (ans % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}