#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010;

int x, y, z;

int main()
{
    cin >> x >> y >> z;
    x -= z;

    cout << x / (y + z) << endl;
    return 0;
}
