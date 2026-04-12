#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >> N;
  vector<int> MY(N);
  for(int i=0;i<N;i++){
    cin >> MY.at(i);
  }
  int view=1;
  int high=MY.at(0);
  for(int i=1;i<N;i++){
    if(high<=MY.at(i)){
      view++;
      high=MY.at(i);
    }
  }
  cout << view << endl;
}