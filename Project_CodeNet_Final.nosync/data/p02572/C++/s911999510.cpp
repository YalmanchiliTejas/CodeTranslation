#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 1e9 + 7, N = 200'010;
ll a[N];

int main() {
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sum %= M;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        if (sum < 0) sum += M;
        res = (res + a[i] * sum) % M;
    }
    printf("%lld\n", res);
}
