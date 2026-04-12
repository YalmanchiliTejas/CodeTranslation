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
    int a, b;
    vector<int> V(101);
    vector<int> S;
    while(scanf("%d,%d", &a, &b), a){
        V[a] = b;
        S.emplace_back(b);
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    reverse(S.begin(),S.end());
    while(cin >> a){
        cout << lower_bound(S.begin(),S.end(), V[a], greater<>()) - S.begin()+1 << "\n";
    }
    return 0;
}
