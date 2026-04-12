#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,W = 0,ans = 0;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    if (A.at(i) >= W){
      ans++;
      W = A.at(i);
    }
  }
  cout << ans << endl;
}