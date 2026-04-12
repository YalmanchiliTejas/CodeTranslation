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
  int ai;
  for(int i=0; i<N; i++){
    cin >> ai;
    a[i] = -ai;
  }
  
  vector<int> chains;
  chains.push_back(a[0]);
  for(int i=1; i<N; i++){
    auto it = lower_bound(chains.begin(), chains.end(), a[i]+1);
    if (it == chains.end()){
      chains.push_back(a[i]);
    }else {
      *it = a[i];
    }
  }
  cout << chains.size() << endl;
  return 0;
}