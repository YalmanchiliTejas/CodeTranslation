#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++) cin >> H.at(i);
  
  int cnt = 0;
  int highest = 0;
  
  for(int i = 0; i < N; i++){
    highest = max(highest, H.at(i));
    if(H.at(i) >= highest) cnt++;
  }
  
  cout << cnt << endl;
}