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

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
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
    ll x;
    cin >> n >> x;
    vector<ll> X(n + 1), P(n + 1);
    X[0] = 1, P[0] = 1;
    for(int i = 0; i < n; ++i){
        X[i + 1] = X[i] * 2 + 3;
        P[i + 1] = P[i] * 2 + 1;
    }
    ll ans = 0;
    while(n >= 0 && x > 0){
        if(x == X[n]){
            ans += P[n];
            break;
        }
        ll bound = X[n] >> 1;
        if(x <= bound){
            if(x == bound){
                ans += P[n - 1];
                break;
            }
            --x, --n;
        }
        else{
            ans += P[--n] + 1;
            x -= bound + 1;
        }
    }
    cout << ans << endl;
}