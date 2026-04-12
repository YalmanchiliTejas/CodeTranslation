#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    //2 * C = A + B

    //cout << 2 * c * max(x, y) << '\n' << x * a + b * y << ' ' << 2 * c * x + (y - x) * b << '\n' << 2 * c * y + (x - y) * a << '\n';
    long long answer = 2 * c * max(x, y);

    answer = min(answer, x * a + b * y);

    x <= y? answer = min(answer, 2 * c * x + (y - x) * b) : answer = min(answer, 2 * c * y + (x - y) * a);

    cout << answer << '\n';
}
