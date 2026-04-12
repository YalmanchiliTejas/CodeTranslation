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
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<int, pair<int, int>> PP;
typedef pair<P, int> PPi;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int b = 1; b <= n; ++b){
        if(k >= b)  continue;
        int per = b - k;
        int cnt = n / b;
        ans += (ll)cnt * per;
        int lb = b * cnt + k;
        ans += max(0, n - lb + 1);
        if(k == 0)  --ans;
    }
    cout << ans << endl;
}