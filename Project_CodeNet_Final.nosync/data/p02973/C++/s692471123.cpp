#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli > plli;
typedef vector<lli> vlli;
typedef vector<plli > vplli;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lcm(a, b) ((a * b) / gcd(a, b))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define UN(v) sort(all(v)), v.resize(unique(all(v))-v.begin())

#define endl '\n'

const long long INF = 100000000000000000;
const long long MOD = 1000000007;
const long long MAXN = 100005;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli gcd(lli a , lli b) {
    if(b == 0) return a;
    a %= b;
    return gcd(b,a);
}

void solve() {
    lli n;
    cin >> n;

    lli a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset<lli> last;

    for (int i = 0; i < n; ++i) {
        auto it = last.lower_bound(a[i]);

        if (it == last.begin()) {
            last.insert(a[i]);
        } else {
            it--;
            last.erase(it);
            last.insert(a[i]);
        }
    }
   cout << last.size() << "\n";
}

int main()
{
    IOS;
    lli t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}