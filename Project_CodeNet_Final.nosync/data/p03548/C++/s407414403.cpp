#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define MOD 1000000007

using ll = long long;


int main(void) {
    int x,y,z;
    cin >> x >> y >> z;
    int ans;
    ans = (x - z) / (y + z);
    cout << ans << endl;
    return 0;
}

