#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int maxN = 2e5 + 10;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PINT pair < int, int >
#define NUM_SET_BIT __builtin_popcountll
#define BIT(x, i) ((x >> i) & 1)

deque < int > b;
int n, a[maxN];

int main() {
    cin >> n;
    FORU(i, 1, n) cin >> a[i];
    bool head = false;
    FORU(i, 1, n) {
        if (head) b.push_front(a[i]);
        else b.push_back(a[i]);
        head = !head;
    }
    if (head) reverse(b.begin(), b.end());
    for (auto x : b) cout << x << " ";
}
