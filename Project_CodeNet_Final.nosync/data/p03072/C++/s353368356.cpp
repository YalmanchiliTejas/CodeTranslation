#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

typedef std::uint64_t u64;
typedef std::int64_t  i64;
typedef std::uint32_t u32;
typedef std::int32_t  i32;

using namespace std;

#define swap(a, b)    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while(0)
#define repd(i, a, b) for(typeof(b) i = (a); (i) < (b); ++i)
#define rep(i, n)     repd(i, 0, n)
#define dump(x)       cerr << #x << " = " << (x) << endl
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl

int main(int argc, const char* argv[]) {
  u64 n;
  cin >> n;
  
  u64 h[n];
  rep(i, n) {
    cin >> h[i];
  }

  u64 ret = 0;
  u64 maxh = 0;
  rep(i, n) {
    if(h[i] >= maxh) {
      ++ret;
      maxh = h[i];
    }
  }
  
  cout << ret << endl;
  
  return 0;
}
