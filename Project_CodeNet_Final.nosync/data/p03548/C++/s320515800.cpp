#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 

using namespace std;

int main() {
    int X, Y, Z;

    cin >> X >> Y >> Z;

    int width = X - Z;

    int ans = width / (Y + Z);

    cout << ans << endl;
    return 0;
}