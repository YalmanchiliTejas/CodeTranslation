#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  multiset<int> S;
  S.insert(-1);
  S.insert(1e9+1);
  for(int i = 0; i < N; ++i){
    auto itr = (--S.lower_bound(A[i]));
    // cerr << A[i] << " " << *itr << endl;
    if(*itr != -1){
      S.erase(itr);
    }
    S.insert(A[i]);
  }
  // for(auto s : S){
  //   cerr << s << endl;
  // }
  cout << S.size()-2 << endl;
}
