#include <bits/stdc++.h>
#define rep(n) for (int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define dump(x) cout << " " << #x << "=" << x
#define vdump(v) for(size_t T=0; T<v.size(); ++T){cout << " " << #v << "[" << T << "]=" << v[T];} cout << endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int n;
    cin >> n;
    int ans = 0;
    repeat_from_to(i, 1, n) {
        ans += 800;
        if (i % 15 == 0) {
            ans -= 200;
        }
    }
    cout << ans << endl;
    return 0;
}