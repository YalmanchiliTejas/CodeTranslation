#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;

int main(int argc, const char * argv[]) {
    ll x, y, z, ans, tmp;
    cin >> x >> y >> z;
    
    tmp = x % y;
    ans = x / y;
    while(!(tmp >= z * (ans + 1))){
        x -= y;
        ans--;
        tmp += y;
    }
    cout << ans << endl;
    return 0;
}
