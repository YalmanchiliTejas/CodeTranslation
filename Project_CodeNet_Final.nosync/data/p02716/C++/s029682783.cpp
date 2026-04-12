// 10101010101
/*
f(i, j) = max(f(i+2, j-1)+v[i], f(i+1, j))
len-i >=  2*j
*/
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;

const int N = 3e5;
int n;
int arr[N];
map<pair<int, int>, ll> cache;

ll f(int i, int j) {
    if (n - i < 2 * j - 1) return -(ll)1e17;
    if (j == 0) return 0;
    if (i == n) return -(ll)1e17;
    if (cache.find({i, j}) == cache.end()) {
        ll value = max(f(i + 2, j - 1) + arr[i], f(i + 1, j));
        return cache[{i, j}] = value;
    } else {
        return cache[{i, j}];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    ll ans = f(0, n / 2);
    printf("%lld\n", ans);
    return 0;
}