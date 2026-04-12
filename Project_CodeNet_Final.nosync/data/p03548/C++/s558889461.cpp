#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    int x, y, z;
    cin >> x >> y >> z;
    int sum = 0;
    int cnt = 0;
    while (sum <= x - z) {
        sum += y + z;
        ++cnt;
    }
    cout << cnt - 1 << endl;
    return 0;
}