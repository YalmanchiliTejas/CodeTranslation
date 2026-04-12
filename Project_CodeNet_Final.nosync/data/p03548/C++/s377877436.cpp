#include <iostream>
using namespace std;
int main() {
    int x, y, z; cin >> x >> y >> z;
    x = x - z;
    int ans = x / ( y + z);
    cout << ans << endl;
}