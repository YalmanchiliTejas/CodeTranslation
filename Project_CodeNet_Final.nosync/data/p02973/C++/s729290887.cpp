#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  multiset<int> mst;
  mst.insert(A[0]);
  for(int i = 1; i < N; i++) {
    if(A[i] > *(mst.begin())) {
      auto it = mst.lower_bound(A[i]);
      it--;
      mst.erase(it);
    }
    mst.insert(A[i]);
  }
  cout << mst.size() << endl;
  return 0;
}