#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
using namespace std;

#ifdef __APPLE__
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int N = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;

int a[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    deque<int> b;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            b.push_back(a[i]);
        } else {
            b.push_front(a[i]);
        }
    }
    vector<int> ans;
    for (auto i : b) {
        ans.push_back(i);
    }
    if (n % 2)  {
        reverse(ans.begin(), ans.end());
    }
    for (auto i : ans) {
        printf("%d ", i);
    }
}

int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) {
        solve();
    }
}