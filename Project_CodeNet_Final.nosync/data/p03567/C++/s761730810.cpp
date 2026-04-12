#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  bool res = false;
  for (int i = 0; i < S.size() - 1; i++){
    if (S.at(i) == 'A' && S.at(i+1) == 'C') res = true;
  }
  if (res){
    cout << "Yes";
  } else {
    cout << "No";
  }
}