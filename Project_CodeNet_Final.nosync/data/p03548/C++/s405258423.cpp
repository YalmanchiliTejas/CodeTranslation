#include <bits/stdc++.h>
using namespace std;
// マクロ
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
// 型エイリアス
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int sum = y + 2 * z;
    int ans = 1;
    while(sum + y + z <= x) {
        ans++;
        sum+= y + z;
    }

    cout << ans << endl;
}