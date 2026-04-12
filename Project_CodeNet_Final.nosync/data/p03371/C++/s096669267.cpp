#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (c * 2 <= a and c * 2 <= b)
    {
        cout << c * 2 * max(x, y) << endl;
    }
    else if (c * 2 <= a)
    {
        // aを買うよりabを買ったほうが有利
        cout << c * 2 * x + b * max(y - x, 0) << endl;
    }
    else if (c * 2 <= b)
    {
        // bを買うよりabを買ったほうが有利
        cout << c * 2 * y + a * max(x - y, 0) << endl;
    }
    else if (c * 2 <= a + b)
    {
        cout << c * 2 * min(x, y) + a * (x - min(x, y)) + b * (y - min(x, y)) << endl;
    }
    else
    {
        cout << a * x + b * y << endl;
    }
}