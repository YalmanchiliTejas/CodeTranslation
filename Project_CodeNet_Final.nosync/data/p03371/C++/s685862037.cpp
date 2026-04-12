#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int answer = INT_MAX;
    for (int k = 0; k <= 100000; k++)
    {
        answer = min(answer, 2 * c * k + max(x - k, 0) * a + max(y - k, 0) * b);
    }

    cout << answer << endl;
}