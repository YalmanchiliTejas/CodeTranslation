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
#include <assert.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int MAXN = 50;
ll a[MAXN + 1];
int n;

bool check() {
    for(int i = 0; i < n; i++)
        if(a[i] >= n)
            return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    while(!check()) {
        ll sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[i] / n;
        ans += sum;
        for(int i = 0; i < n; i++)
            a[i] = a[i] % n + sum - a[i] / n;
    }
    cout << ans << "\n";
    return 0;
}
