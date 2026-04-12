#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <climits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

using Pair = pair<int, int>;
using lint = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

// const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main(){
  lint n, x, m;
  cin >> n >> x >> m;
  vector<int> used(m, -1);
  vector <lint > a;
  a.push_back(x);
  used[x] = 0;
  vector<lint> sum;
  while(1){
    int b = a[a.size() - 1] * a[a.size() - 1] % m;
    if(b==0){
      lint ret = 0;
      rep(i, a.size()) ret += a[i];
      cout << ret << endl;
      return 0;
    } else if (used[b]!=-1){
      sum.push_back(0);
      for (int i = used[b]; i < a.size();i++){
        sum.push_back(sum[sum.size() - 1] + a[i]);
      }
      break;
    } else {
      used[b] = a.size();
      a.push_back(b);
    }
  }
  if(n<=a.size()){
    int ret = 0;
    rep(i, n) ret +=a[i];
    cout << ret << endl;
  }else{
    lint ret = 0;
    rep(i, a.size()) ret += a[i];
    n -= a.size();
    ret += sum[sum.size() - 1] * (n / (sum.size() - 1));
    ret += sum[n % (sum.size() - 1)];
    cout << ret << endl;
  }
}
