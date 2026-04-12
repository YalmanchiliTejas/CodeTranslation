#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int x, y, z, cnt=0;
    cin >> x >> y >> z;
    while(x >= z) {
        x -= y + z;
        if (x >= z) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}