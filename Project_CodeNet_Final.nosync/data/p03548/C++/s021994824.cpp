#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int x, y, z;
int main(){
    cin >> x >> y >> z;
    int ans = 0;
    x -= z;
    ans += x / (y + z);
    cout << ans << endl;
    return 0;
}
