#include <cstdio>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main() {
    int n, m;
    lli s = 0;
    scanf("%d%d", &n, &m);
    int i;
    for (i=1; i<=n; ++i) {
        if (m == 0) s += n;
        else s += max(i - m, 0) * (lli)(n / i) + max(n % i - m + 1, 0);
    }
    printf("%lld\n", s);
    return 0;
}
