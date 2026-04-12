#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    x -= z;
    while (true) {
        if (x - y >= z) {
            x -= y;
            x -= z;
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}