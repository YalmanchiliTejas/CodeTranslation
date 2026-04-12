
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
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
#define f(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
#define T int t = 0; cin >> t; while(t--)
#define b_e(a) a.begin(), a.end()
typedef long long ll;
typedef  long double lld;
const ll mod = 1e9 + 7;
const ll mx = 2e6 + 5;
int dp[101][4][3];
vector<int>num;
int sz, k;
int digit_dp(int i, int cnt, int f){
    if(cnt > k)return 0;
    if(i == sz){
        return cnt == k ? 1 : 0;
    }
    if(dp[i][cnt][f] != -1)return dp[i][cnt][f];
    int res = 0;
    int LMT = (f == 1) ? 9 : num[i];
    for(int digit = 0; digit <= LMT; ++digit){
        res += digit_dp(i + 1, ((digit != 0) ? cnt + 1 : cnt), (f == 0 && digit == LMT) ? 0 : 1);
    }
    return dp[i][cnt][f] = res;
}
int solve(string n){
    f(i, n.size())num.pb(n[i] - '0');
    sz = num.size();
    return digit_dp(0, 0, 0);
}

void input(){
    memset(dp, -1, sizeof(dp));
   string n;
   cin >> n >> k;
   cout << solve(n) << endl;
    
}
int main(){
    input();
    return 0;
}