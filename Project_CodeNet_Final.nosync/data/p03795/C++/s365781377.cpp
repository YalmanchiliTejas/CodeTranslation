#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int n, x, y;
    cin >> n;
    x = n * 800;
    y = n / 15 * 200;
    cout << x - y << endl;
    // end

    return 0;
}
