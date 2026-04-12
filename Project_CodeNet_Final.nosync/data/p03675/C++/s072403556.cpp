#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const double eps = 1e-9;

const int MAX_N = (int)1e5 + 5;
const int mod = (int)1e9 + 7;

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    deque < int > q;
    bool tp = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if (!tp)
            q.push_back(x);
        else
            q.push_front(x);
        tp ^= 1;
    }
    if (tp)
        reverse(q.begin(), q.end());
    for (auto i : q)
        printf("%d ", i);
    return 0;
}
