#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> S(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &S[i+1]);
        S[i+1] += S[i];
    }
    map<ll, int> m;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(m.count(S[i])) ans = max(ans, i-m[S[i]]);
        else m[S[i]] = i;
    }
    cout << ans << "\n";
    return 0;
}
