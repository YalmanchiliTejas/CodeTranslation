#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> D){
  int N = D.size();
  int max_d = 0;
  for(int i = 0; i < N; ++i){
    if(max_d < i*10){
      return false;
    }
    max_d = max(max_d,i*10+D[i]);
  }
  return true;
}

int main(){
  int N;
  cin >> N;
  vector<int> D(N);
  for(int i = 0; i < N; ++i) cin >> D[i];
  bool f = solve(D);
  reverse(D.begin(), D.end());
  f &= solve(D);
  if(f) cout << "yes" << endl;
  else cout << "no" << endl;
}

