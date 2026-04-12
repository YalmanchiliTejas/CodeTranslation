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
    vector<int> a(12);
    for (auto &&i : a) scanf("%d", &i);
    sort(a.begin(),a.end());
    if(a[0] == a[3] && a[4] == a[7] && a[8] == a[11]) puts("yes");
    else puts("no");
    return 0;
}
