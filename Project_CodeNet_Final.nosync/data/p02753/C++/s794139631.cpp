#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  int b=0;
  cin >> a;
  
  for(int i=0; i<3; i++){
    if(a.at(i)=='A') b++;
    else if(a.at(i)=='B') b--;
  }
  
  if(abs(b)<3){
    cout << "Yes" << endl;
  }
  else if(abs(b)==3){
    cout << "No" << endl;
  }
}