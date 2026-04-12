#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    long long a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    long long sum = std::numeric_limits<long long>::max();

    for (long long i = 0; i < 10000000; i++)
    {
        long long cost = i * c;
        cost += a * max(0LL, x - i / 2LL);
        cost += b * max(0LL, y - i / 2LL);
        sum = min(sum, cost);
    }

    cout << sum << endl;
}
