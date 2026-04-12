#include <iostream>
using namespace std;
int main() {
    int x, y, z, able, yz, ans;
    cin >> x >> y >> z;
    able = x - z;
    yz = y + z;
    ans = able / yz;
    cout << ans << endl;
    return 0;
}

