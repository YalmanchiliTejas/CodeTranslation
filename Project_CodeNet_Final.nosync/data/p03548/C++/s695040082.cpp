#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int result = 0;
    int count = 0;
    for(int i = 0; result <= x; ++i) {
        result = y*i + z*(i+1);
        count = i;
    }
    cout << count - 1 << endl;
    return 0;
}
