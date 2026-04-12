#include <bits/stdc++.h>
using namespace std;


int main(){
  string S;
  cin >> S;
  int num_A = 0;
  for(auto& s : S){
    if(s=='A') num_A++;
  }
  cout << (num_A==0||num_A==3?"No":"Yes") << endl;
  return 0;
}
