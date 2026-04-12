#include <iostream>
using namespace std;
int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    cin >> x >> y >> z;
    int ans = (x - z) / (y + z);
    cout << ans;
    return 0;
}