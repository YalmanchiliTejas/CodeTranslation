#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <assert.h>
#include <numeric>
#include <math.h>
#include <climits>
#include <stack>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename T>
inline bool sign(T A) {
    return (A>0)-(A<0);
}

#define REP(i,s,n) for(int i=s; i!=n; i+=sign(n-s))
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

#define MOD (1'000'000'000+7)

bool _less(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

template <template<class,class,class...> class C, typename K, typename V, typename... Args>
V map_get(const C<K,V,Args...>& m, K const& key, const V & defval)
{
    typename C<K,V,Args...>::const_iterator it = m.find( key );
    if (it == m.end())
        return defval;
    return it->second;
}

bool checked[3001][3001];
ll dp[3001][3001];
vector<int> a;
int N;

ll solve(int l, int r) {
    if (l > r) return 0;
    if (checked[l][r]) {
        return dp[l][r];
    }
    
    if ((l-1+N-r)%2 == 0) {
        dp[l][r] = max(solve(l+1, r) + a[l], solve(l, r-1) + a[r]);
    } else {
        dp[l][r] = min(solve(l+1, r) - a[l], solve(l, r-1) - a[r]);
    }
    checked[l][r] = true;
    return dp[l][r];
}

int main() {
    cin >> N;
    a.resize(N+1);
    REP(i, 0, N) {
        cin >> a[i+1];
    }

    cout << solve(1, N) << endl;
}
