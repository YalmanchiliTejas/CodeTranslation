#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int out = INT_MAX;
    for (int i = 0; i <= 100000; i++)
    {
        out = min(out, 2 * c * i + max(0, x - i) * a + max(0, y - i) * b);
    }
    cout << out << endl;
}