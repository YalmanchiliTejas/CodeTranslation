#include <bits/stdc++.h>
using namespace std;


int main(){
  string str;
  cin >> str;
  int count = 0;
  
  for (int i=0; i < 3; i++){
    if(str.at(i) == 'A'){
      count++;
    }
  }
  
  if (count == 3 || count == 0){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}

