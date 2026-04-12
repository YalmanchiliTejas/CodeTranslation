#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin >> H.at(i);
  }
  int Highest=H.at(0),Count=1;
  for(int i=1; i<N; i++){
    if(Highest<=H.at(i)){
      Highest=H.at(i);
      Count++;
    }
  }
  cout << Count << endl;
}