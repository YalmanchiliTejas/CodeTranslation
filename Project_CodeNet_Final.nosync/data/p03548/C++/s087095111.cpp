#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int x,y,z; cin >> x >> y >> z;
    int ans = 0;
    x-=z;
    while (x >= y+z) {
        ans++;
        x -= y+z;
    }
    cout << ans << endl;
    return 0;
}