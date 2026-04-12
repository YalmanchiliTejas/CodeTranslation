// 2019/07/11
// AtCoder Beginner Contest 078 - B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z, wkw, ans;
    cin >> x >> y >> z;
    wkw = y + z * 2;
    ans = 1;
    while(wkw < x){
        wkw = wkw + y + z;
        ans = ans + 1;
    }
    if(wkw != x){
        ans = ans - 1;
    }
    cout << ans;
}