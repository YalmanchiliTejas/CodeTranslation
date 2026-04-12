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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n;
    cin >> n;
    vector<int> ts(n);
    for (auto &&i : ts) scanf("%d", &i);
    int mx = *max_element(ts.begin(),ts.end());
    auto d = divisor(mx);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int val = INF<int>;
        for (auto &&x : d) {
            if(x >= ts[i]) val = min(val, x-ts[i]);
        }
        ans += val;
    }
    cout << ans << "\n";
    return 0;
}
