//created by pyoxiao on 2020/04/12
#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define CL(a, b) memset(a, b, sizeof(a))
using namespace std;
const int mod = 1e9 + 7;
LL fpow(LL a, LL b, LL p = mod){LL ans = 1; a %= p; while(b) {if(b & 1) ans = ans * a % p; b >>= 1; a = a * a % p;} return ans;}
LL gcd(LL a, LL b){return b == 0 ? a : gcd(b, a % b);}
const int N  = 2e5 + 7;
int n;
LL res[N], a[N];
LL odd_sum[N], even_sum[N];
LL mmax[N];
void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", a + i);
        if(i & 1) {
            if(i == 1) odd_sum[i] = a[i];
            else odd_sum[i] = odd_sum[i - 1] + a[i];
            even_sum[i] = even_sum[i - 1];
        } else {
            if(i == 2) even_sum[i] = a[i];
            else even_sum[i] = even_sum[i - 1] + a[i];
            odd_sum[i] = odd_sum[i - 1];
        }
    }
    LL ans = max(even_sum[n], odd_sum[n]);
    if(n % 2 == 0) {
        for(int i = 3; i <= n - 1; i += 2) {
            ans = max(ans, odd_sum[i - 1] + even_sum[n] - even_sum[i - 1]);
        }
        printf("%lld\n", ans);
        return;
    }
    //cout << ans << '\n';
    ans = max(even_sum[n - 1], odd_sum[n - 1]);
    for(int i = n - 1; i >= 2; i -= 2) {
        if(i == n - 1) mmax[i] = odd_sum[n] - odd_sum[i - 1] - even_sum[n] + even_sum[i - 1];
        else mmax[i] = max(mmax[i + 2], odd_sum[n] - odd_sum[i - 1] - even_sum[n] + even_sum[i - 1]);
    }
    for(int i = 2; i <= n; i ++) {
        if(i & 1) {
            res[i] = even_sum[n] - even_sum[i] + odd_sum[i - 1];
        } else {
            res[i] = odd_sum[n] - odd_sum[i] + even_sum[i - 1];
        }
        ans = max(ans, res[i]);
    }
    for(int i = 3; i <= n - 4; i += 2) {
        ans = max(ans, res[i] + mmax[i + 3]);
    }
    for(int i = 4; i <= n - 1; i += 2) {
        ans = max(ans, odd_sum[n] - odd_sum[i] + odd_sum[i - 3]);
    }
    printf("%lld\n", ans);
}
int main() {
    int T = 1;
    // scanf("%d", &T);
    while(T --) 
        solve();
    return 0;
}