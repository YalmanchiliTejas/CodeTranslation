#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define INF 999999999
typedef long long ll;
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    ans = x /(y+z);
    if(x < ans*(y+z)+z) ans--;
    cout << ans << endl;
}
