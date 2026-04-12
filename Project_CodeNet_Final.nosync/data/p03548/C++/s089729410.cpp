#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    int ans = 0;
    ans = (x - z) / (y + z);

    cout << ans << endl;

    return 0;
}