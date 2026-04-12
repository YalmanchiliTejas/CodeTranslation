#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    int rest = x-y-2*z,ans = 1;
    while(rest >= y+z){
        ans++;
        rest -= y+z;
    }
    cout << ans << endl;
}