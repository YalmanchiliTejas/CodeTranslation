#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int X, Y, Z; cin >> X >> Y >> Z;
    int sum = 0, cnt = 0;
    while(true) {
        sum += Y + Z;
        if (sum + Z > X) break;
        cnt++;
    }
    printf("%d\n", cnt);
}
