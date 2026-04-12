#include <iostream>
#include <algorithm>
#include <iomanip>
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
    int n, q;
    cin >> n >> q;
    vector<int> a(q), b(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--; b[i]--;
    }
    set<int> s;
    vector<int> v(n);
    iota(v.begin(),v.end(), 0);
    int cur = 0;
    s.emplace(0); s.emplace(1);
    for (int i = 0; i < q; ++i) {
        swap(v[a[i]], v[b[i]]);
        if(a[i] == cur || b[i] == cur) cur ^= a[i]^b[i];
        if(cur) s.emplace(v[cur-1]);
        if(cur != n-1) s.emplace(v[cur+1]);
    }
    cout << s.size() << "\n";
    return 0;
}