#include <bits/stdc++.h>
#define rep(n) for (int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define repeat_from_reverse(i, m, n) for( int i = (n) - 1; (i) >= (m); --(i) )
#define el cout<<endl
#define dump(x) cout << " " << #x << "=" << x
#define vdump(v) for(size_t t=0; t<v.size(); ++t){cout << " " << #v << "[" << t << "]=" << v[t];} cout << endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;
    
    int ans = a * x + b * y;

    if (x < y) {
        int tmp = 2 * x * c;
        tmp += (y - x) * b;
        ans = min(ans, tmp);
    }
    else {
        int tmp = 2 * y * c;
        tmp += (x - y) * a;
        ans = min(ans, tmp);
    }
    
    ans = min(ans, 2 * max(x, y) * c);
    
    cout << ans << endl;
}