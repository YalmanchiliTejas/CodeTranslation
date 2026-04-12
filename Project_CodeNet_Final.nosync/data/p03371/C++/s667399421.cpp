#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

using namespace std;

int main() {
    

    
    int a, b, c, x, y;
    
    cin >> a >> b >> c >> x >> y;
    
    long long mincost = max(x, y) * 2 * c;
    long long mid;
    if (x > y)
    {
        mid = (x - y) * a;
    }
    else
    {
        mid = (y - x) * b;
    }
    mincost = min(mincost, min(x, y) * 2 * c + mid);
    mincost = min(mincost, (long long)(x * a + y * b));
    
    cout << mincost << endl;
    
    return 0;
}