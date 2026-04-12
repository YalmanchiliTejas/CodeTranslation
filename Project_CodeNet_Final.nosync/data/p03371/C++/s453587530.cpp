#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;    
    cout << min(a + b, 2 * c) * min(x, y) + min(a, 2 * c) * max(0, x - y) + min(b, 2 * c) * max(0, y - x) << endl;
    return 0;
}