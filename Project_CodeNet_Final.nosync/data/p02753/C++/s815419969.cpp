#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  bool is_A = false , is_B = false;
  for(char c : s){
  	if(c == 'A')is_A = true;
    else is_B = true;
  }
  if(is_A && is_B)
    cout << "Yes\n";
  else 
    cout << "No\n";
  
  
}