#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

ll arr[200001];

int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);

    ll ans = 0, M = 1000000007, sum = arr[0];

    for(int i=1; i<n; i++) {
        ans = (ans + (sum * arr[i])) % M;
        sum = (sum + arr[i]) % M;
    }

    printf("%lld\n", ans);

    return 0;
}