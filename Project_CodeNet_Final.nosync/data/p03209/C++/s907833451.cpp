#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = int64_t;
#define MAX_N 1010
#define MAX_M 100010
const long long mod = pow(10,9)+7;
#define vec vector<int>
#define vecll vector<ll>
#define vecllvec vector<vector<ll>>
#define vecb vector<bool>
#define vecBvec vector<vector<bool>>
#define vecst vector<string>
#define veche vector<char>
#define vecd vector<double>
#define vecvec vector<vector<int>>
#define vecDvec vector<vector<double>>
#define vecHvec vector<vector<char>>
#define all(x) (x).begin(),(x).end()
#define ent cout<<endl
#define printvec(vec) for(int aqw=0;aqw<vec.size();aqw++){cout<<vec[aqw]<<" ";}ent;
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INF 1e+9
#define print(x) cout<<x<<endl;
using P = pair<int, int>;
#define PLL pair<ll, ll>;
#define MAX_V 10010
#define PI 3.141592653589793
#define vecP vector<P>
 //cout << setprecision(15) << std::fixed;

vecll c,p;

ll ret_p(ll n, ll x) {
    if (x == c[n]) return p[n];
    
    ll ans = 0;
    x--;
    
    if (x > 0) {
        ll l = min(x, c[n - 1]);
        ans += ret_p(n - 1, l);
        x -= l;
    }
    
    if (x > 0) {
        ans++;
        x--;
    }
    
    if (x > 0) {
        ll l = min(x, c[n - 1]);
        ans += ret_p(n - 1, l);
        x -= l;
    }
    return ans;
}

int main() {
    ll N, X;
    cin >> N >> X;
    c.resize(N + 1);
    p.resize(N + 1);
    c[0] = p[0] = 1;
    for (int i = 1; i <= N; i++) {
        c[i] = c[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    print(ret_p(N, X));
}

