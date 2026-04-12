#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, ab, x, y, M, m;
    cin >> a >> b >> ab >> x >> y;
    M = max(x, y);
    m = min(x, y);
    cout << min({a*x + b*y, ab*M*2,
                    ab*m*2 + (x > y ? a*(x-m) : b*(y-m))}) << endl;
    return 0;
}