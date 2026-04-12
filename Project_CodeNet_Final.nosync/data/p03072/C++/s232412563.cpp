#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n,ans=0,height=0;
  cin >> n;
  vector<int> v=input(n);
  rep(i,n){
    if(height<=v[i]){
      ans++;
    }
    height=max({height,v[i]});
  }
  cout << ans << endl;
}