#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int min_price = a * x + b * y;
    int num_max = max(x, y);
    for (int i = 2; i <= num_max * 2; i += 2) {
        int tmp = c * i;    // AB pizza
        tmp += a * max((x - i / 2), 0);
        tmp += b * max((y - i / 2), 0);

        if (tmp < min_price)
            min_price = tmp;
    }

    cout << min_price << '\n';
}
