#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
pii A[200000];
int ans[200000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + n);
    for (int i = 0; i + i < n; ++i) ans[A[i].second] = A[n >> 1].first;
    for (int i = n >> 1; i < n; ++i) ans[A[i].second] = A[(n >> 1) - 1].first;
    for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
    return 0;
}