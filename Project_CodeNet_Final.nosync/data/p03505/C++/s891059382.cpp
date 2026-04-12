#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    long long k, a, b;
    cin >> k >> a >> b;

    if (a >= k) return cout << 1 << endl, 0;
    if (a <= b) return cout << -1 << endl, 0;

    long long t = (k - a) / (a - b) + !!((k - a) % (a - b));
    cout << 2 * t + 1 << endl;

    return 0;
}
