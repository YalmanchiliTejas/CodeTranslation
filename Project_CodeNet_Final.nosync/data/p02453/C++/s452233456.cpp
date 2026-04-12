#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <set>
#include <cstdio>
#include <bitset>
#include <functional>
#include <tuple>
#include <list>
#include <deque>
using namespace std;
typedef pair<int, int> P;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef vector<int> VI;

int a[200010];
int b[200010];
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int n; cin >> n;
    REP(i, n) cin >> a[i];
    
    int q; cin >> q;
    REP(i, q){
        int k; cin >> k;
        int ptr= lower_bound(a, a+n, k) - a;
        cout << ptr << endl;
    }
	return 0;
}
