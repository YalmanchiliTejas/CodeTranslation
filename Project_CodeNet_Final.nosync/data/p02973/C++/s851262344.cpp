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
  vector<int>a(n);
  rep(i,n) cin >> a[i];

  set<P> v;
  rep(i,n){
    int ii = n-1-i;
    auto itr = v.lower_bound(P(a[ii]+1,ii));
    if(itr!=v.end()){
      v.erase(itr);
    }
    v.emplace(a[ii],ii);
  }
  cout << v.size() << endl;
}
