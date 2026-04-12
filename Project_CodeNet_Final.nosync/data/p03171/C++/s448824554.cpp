#include <bits/stdc++.h>
using namespace std;
#define N 3050
typedef long long ll;
ll a[N],ps[N],memo[N][N];
int n;

void preCompute() {
    for (int i = 1 ; i <= n ; i++)
        ps[i] = ps[i - 1] + a[i];
}

ll sum(int l , int r) {
    return ps[r] - ps[l - 1];
}

ll dp(int l , int r) {
    if (l == r) return a[l];
    ll &sol = memo[l][r];
    if (sol != -1) return sol;
    return sol = max(
        a[l] + (sum(l + 1 , r) - dp(l + 1 , r)) ,
        a[r] + (sum(l , r - 1) - dp(l , r - 1))
    );
}

int main() {
    scanf("%d" , &n);
    ll sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        scanf("%lld" , &a[i]);
        sum += a[i];
    }
    preCompute();
    memset (memo , -1 , sizeof memo);
    ll x = dp(1 , n);
    ll y = sum - x;
    printf("%lld\n" , x - y);
}
