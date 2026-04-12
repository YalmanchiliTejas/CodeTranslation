#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);
  
  multiset<int> num;
  num.insert(-1);
  for( int i = 0; i < N; i++ ){
    bool fg = 0;
    auto Iter = num.lower_bound(A.at(i));
    if( Iter != num.begin() ){
      num.erase(--Iter);
    }
    num.insert(A.at(i));
  }
  cout << num.size() << endl;
  
}