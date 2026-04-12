#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// 400012- 128


void oneCase() {
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << "\n";
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}
