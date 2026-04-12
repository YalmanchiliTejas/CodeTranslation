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

int main(){
    int n;
    scanf("%d", &n);
    lint s[n];
    rep(i, n) scanf("%lld", &s[i]);
    lint ans = 0;
    For(i, 1, n/2){
        lint tmp = 0;
        lint ttmp = 0;
        if((n-1)%i == 0){
            for(int j=0; j<n-1-j; j+=i){
                ttmp += s[j] + s[n-1-j];
                tmp = max(tmp, ttmp);
            }
        }
        else{
            for(int j=0; i<n-1-j; j+=i){
                ttmp += s[j] + s[n-1-j];
                tmp = max(tmp, ttmp);
            }
        }
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
}