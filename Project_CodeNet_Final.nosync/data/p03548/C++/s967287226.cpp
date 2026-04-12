#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;
    int res = 0;
    x -= z;
    while(true) {
        x -= y;
        x -= z;
        if(x < 0) break;
        res++;
    }
    cout << res;

    return 0;
}