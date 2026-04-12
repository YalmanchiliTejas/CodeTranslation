#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int ans = 0, h = 0;
  rep(i,n){
    int hi;
    cin >> hi;
    if(hi>=h){
      ++ans;
      h = hi;
    }
  }
  cout << ans << endl;
}
