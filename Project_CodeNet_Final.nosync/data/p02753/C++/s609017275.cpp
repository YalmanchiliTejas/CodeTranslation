#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool kusa = false;
   for (int i = 0; i < 2; i++){
     if (s.at(i) != s.at(i + 1)){
       kusa = true;
     }
     if (kusa){break;}
   }
  if (kusa){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
    
}
