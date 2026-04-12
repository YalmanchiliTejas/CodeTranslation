#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 100;
ll arr[maxn], pre[maxn];

int main(){
    int n;
    while (~scanf("%d", &n)) {
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            pre[i] = (pre[i - 1] + arr[i]) % mod;
        }
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ans = (ans + arr[i] * ((pre[n] - pre[i] + mod) % mod) % mod) % mod;
        }
        printf("%lld\n", ans);
    }


    return 0;
}