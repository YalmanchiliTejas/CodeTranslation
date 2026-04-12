#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

using ll = long long;
using ull = uint64_t;
using P = pair<int, int>;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i)  cin >> s[i];

    ll ans = 0;
    for(int k = 1; k < n / 2; ++k){
        vector<ll> LeftSum(1, 0), RightSum(1, 0);
        if((n - 1) % k == 0){
            for(int i = n - k - 1; i >= n / 2; i -= k){
                RightSum.emplace_back(RightSum.back() + s[i]);
            }
        } else {
            for(int i = n - k - 1; i > k; i -= k){
                RightSum.emplace_back(RightSum.back() + s[i]);
            }
        }
        int sz = RightSum.size();
        for(int i = k; i < k * sz; i += k){
            LeftSum.emplace_back(LeftSum.back() + s[i]);
        }
        if(k * (sz - 1) == n - k * (sz - 1) - 1)    --sz;
        for(int i = 1; i < sz; ++i){
            chmax(ans, LeftSum[i] + RightSum[i]);
        }
    }

    cout << ans << endl;
}