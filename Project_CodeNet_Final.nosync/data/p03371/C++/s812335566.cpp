#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, x, y;
    vector<int> m;

    cin >> a >> b >> c >> x >> y;

    int diffAns = a * x + b * y;
    int sameAns = c * max(x, y) * 2;
    
    int diffPrice = (x > y) ? a : b;
    int mergeAns = c * min(x, y) * 2 + (max(x, y) - min(x, y)) * diffPrice;

    cout << min(min(diffAns, sameAns), mergeAns) << endl;
    
    return 0;
}
