#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y; cin >>a >>b >>c >>x >>y;
    int ret = a*x + b*y;
    if (x<=y) ret = min(ret, 2*c*x + min(b,2*c)*(y-x));
    if (x>=y) ret = min(ret, 2*c*y + min(a,2*c)*(x-y));
    cout << ret << endl;
    return 0;
}