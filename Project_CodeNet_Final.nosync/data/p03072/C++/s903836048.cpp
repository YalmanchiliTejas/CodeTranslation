#include <bits/stdc++.h>
using namespace std;

int main(){

  int N; cin >> N;
  vector<int> H(N, 0);
  for(int i = 0 ; i < N ; ++i){
    cin >> H[i];
  }

  int cnt = 0;
  int max = 0;

  for(int i = 0 ; i < N ; ++i){
    max = std::max(max, H[i]);
    if(max == H[i]) ++cnt;
  }

  cout << cnt << endl;

}