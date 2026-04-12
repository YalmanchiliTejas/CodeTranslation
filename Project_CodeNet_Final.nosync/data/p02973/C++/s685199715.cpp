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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SREP(i,s,n) for(int i=s; (n-i)*sign(n-s)>0; i+=sign(n-s))
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

#define MOD (1'000'000'000+7)


int cdp[200001];

int main(void)
{
    ll N;
    cin >> N;
    map<int, int> s;
    REP(i, N) {
        int A;
        cin >> A;
        auto lb = s.lower_bound(A);
        if (lb != s.begin()) {
            if (prev(lb)->second > 1) {
                s[prev(lb)->first]--;
            } else {
                s.erase(prev(lb));
            }
        }
        s[A]++;
    }
    ll cnt = 0;
    for (auto i : s)
    {
        cnt += i.second;
    }
    
    cout << cnt << endl;
    return 0;
}
