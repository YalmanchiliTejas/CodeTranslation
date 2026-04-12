#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const int maxn = 1e6 + 7;
const LL INF = 1e18;

int main() {
    int n,m;
    cin >> n >> m;
    if(n > m) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
