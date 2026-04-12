#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

lint n, a[50];

int main(){
    scanf("%lld", &n);
    rep(i, n) scanf("%lld", &a[i]);
    lint cnt = 0;
    while(true){
        sort(a, a+n, greater<lint>());
        if(a[0] < n) break;
        lint tmp = (a[0]-n) / n + 1;
        cnt += tmp;
        a[0] -= n * tmp;
        rep(i, n-1) a[i+1] += tmp;
    }
    printf("%lld\n", cnt);
}