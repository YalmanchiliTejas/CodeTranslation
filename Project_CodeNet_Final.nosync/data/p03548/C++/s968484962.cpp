#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 1;
    x -= y + 2 * z;
    ans += x / (y + z);
    cout << ans << endl;
    
}