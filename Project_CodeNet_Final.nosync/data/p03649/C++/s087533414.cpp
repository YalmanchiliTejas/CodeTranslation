#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
vector<ll> arr;

int main() {
    scanf("%d", &N);
    arr.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    ll ans = 1e18;
    for(int i = 0; i <= N; i++) {
        ll r = i;
        ll x = 0;
        for(int j = 0; j < N; j++) {
            if(arr[j] + r - N < 0) continue;
            x += (arr[j] + r - N) / (N + 1) + 1;
        }
        ll q = x - r;
        if(q < 0) continue;
        ans = min(ans, q*(N + 1) + r);
    }
    printf("%lld", ans);
}
