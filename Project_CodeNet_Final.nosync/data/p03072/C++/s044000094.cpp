#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int can_view = 0;
  cin >> N;
  vector<int> height(N);
  for (int i = 0; i < N; i++) {
    cin >> height.at(i);
  }
  int kizyun = height.at(0);
  for (int i = 0; i < N; i++) {
    if(height.at(i) > kizyun){
      can_view++;
      kizyun = height.at(i);
    }else if(height.at(i) == kizyun){
      can_view++;
    }
  }
  cout << can_view << endl;
  
}