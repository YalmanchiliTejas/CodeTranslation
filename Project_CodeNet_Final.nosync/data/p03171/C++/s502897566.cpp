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
#if __cplusplus >= 201103L
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
#endif
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
using namespace std;
const int maxn = 3000+10;
long long a[maxn];
long long dp[maxn][maxn];
int main() {
    int n ;
    cin >> n ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i =  0; i < n;i++){
        dp[i][i] = a[i];
    }
    
    for(int r = 0 ; r < n; r++){
        for(int l = r-1 ; l >= 0; l--){
            dp[r][l]  = max(a[r] - dp[r-1][l],a[l] - dp[r][l+1]);
        }
    }
    cout << dp[n-1][0];
    return 0;
}
