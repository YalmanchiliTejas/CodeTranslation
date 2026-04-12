
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int ans = x / (y + z);
    int tmp = (y + z) * ans;

    if(x - tmp < z) cout << ans - 1 << endl;
    else cout << ans << endl;
    return 0;
}
