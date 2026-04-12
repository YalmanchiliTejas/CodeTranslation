#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> H(N);
  
  for(int &i: H)
    cin >> i;
  
  int max_ = 0;
  int counter = 0;
  
  for(int &i: H){
    if(i >= max_){
      max_ = i;
      counter++;
    }
  }
  
  cout << counter << endl;
}