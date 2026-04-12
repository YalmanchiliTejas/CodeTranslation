#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  cin >> c;
  bool s=false;
  vector<char> vec{'a','i','u','e','o'};
  for (int i=0;i<5;i++){
    if(c==vec.at(i)){
      s=true;
      break;
      
    }
  }
  if(s){
    cout << "vowel" <<endl;
  }
  else{
    cout << "consonant" << endl;
  }
}
