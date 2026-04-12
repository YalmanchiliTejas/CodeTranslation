
#include <bits/stdc++.h>

using namespace std;

typedef long int lint;
typedef long long int llint;

#define INF 1073741824
#define LINF 4611686018000000000
#define MOD 1000000007

int main() {
    int n;
    cin >> n;
    int a;
    llint cnt = 0;
    llint ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = (ans % MOD + (a * (cnt % MOD)) % MOD) % MOD;
        cnt += a;
    }
    cout << ans << endl;
    return 0;
}
