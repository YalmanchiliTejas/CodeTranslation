#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
const int INF = 1<<30;
const ll MOD = 1e9+7;
const double EPS = 1e-9;


int main(int argc, const char * argv[]) {
  int N; cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++)
    cin >> a[i];
  
  
  multiset<int> s;
  s.insert(a[0]);
  for(int i=1; i<N; i++){
    auto it = s.lower_bound(a[i]);
    if (it != s.begin()) {
      it--;
      s.erase(it);
    }
    s.insert(a[i]);
  }
  cout << s.size() << endl;
  return 0;
}