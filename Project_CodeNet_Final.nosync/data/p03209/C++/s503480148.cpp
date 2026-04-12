#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

ll an(ll k){
    return pow(2, k) * 4 - 3;
}

ll pn(ll k){
    return pow(2, k) * 2 - 1;
}

ll burger(ll n, ll k){
    if (n == 0) return 1;
    if (k == 1) return 0;
    if (k <= an(n - 1) + 1) return burger(n - 1, k - 1);
    if (k == an(n - 1) + 2) return pn(n - 1) + 1;
    if (k < an(n)) return pn(n - 1) + 1 + burger(n - 1, k - an(n - 1) - 2);
    if (k == an(n)) return 2 * pn(n - 1) + 1;

    cout << "error" << n << " " << k << endl;
    cout << (1 << n) << endl;
    return 0;
}

int main() {
    ll n , x;
    cin >> n >> x;
    cout << burger(n, x) << endl;

    return 0;
}