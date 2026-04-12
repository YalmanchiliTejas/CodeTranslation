#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main(){
  int N;
  cin >> N;
  vector<i64> A(N);
  for(auto& x : A){
    cin >> x;
  }
  i64 ans = 0;
  while(true){
    i64 sum = 0;
    bool OK = true;
    for(auto x : A){
      sum += x / N;
      if(x >= N) OK = false;
    }
    if(OK) break;

    ans += sum;
    for(auto & x : A){
      i64 X = x;
      x %= N;
      x += sum - (X / N);
    }
  }

  cout << ans << endl;
}
