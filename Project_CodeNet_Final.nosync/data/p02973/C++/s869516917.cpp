#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];

  multiset<int> ms;
  REP(i, N) {
    auto itr = ms.upper_bound(-A[i]);
    if (itr != ms.end()) {
      ms.erase(itr);
    }
    ms.insert(-A[i]);
  }

  cout << ms.size() << endl;
  return 0;
}
