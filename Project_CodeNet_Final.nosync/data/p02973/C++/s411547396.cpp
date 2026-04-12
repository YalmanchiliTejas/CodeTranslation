#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  multiset<int> mst;
  mst.insert(A[N-1]);
  for(int i = N-2; i >= 0; i--) {
    if(A[i] <= *(mst.rbegin())) {
      auto beg = mst.upper_bound(A[i]);
      auto en = beg;
      en++;
      if(beg != mst.end()){
        mst.erase(beg, en);
      }
    }
    mst.insert(A[i]);
  }
  cout << mst.size() << endl;
  return 0;
}