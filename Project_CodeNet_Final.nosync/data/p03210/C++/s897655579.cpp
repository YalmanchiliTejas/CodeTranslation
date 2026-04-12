#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    switch (n)
    {
    case 5:
    case 7:
    case 3:
        cout << "YES" << endl;
        break;
    default:
        cout << "NO" << endl;
        break;
    }
    return 0;
}