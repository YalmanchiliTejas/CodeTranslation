#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

int main(){
    int n, k; cin >> n >> k;
    lint ans = 0;
    For(r, k, n){
        int t = (n-r) / (r+1);
        rep(q, t+1){
            if(q == 0 && r != 0) ans += n - r;
            else if(q != 0) ans += (n-r) / q - r;
        }
    }
    cout << ans << endl;
}