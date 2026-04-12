#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a = 0, b = 0;
  string str;

  cin >> str;

  for(int i = 0; i < 3; i++){
    if(str.at(i) == 'A'){
      a++;
    }else if(str.at(i) == 'B'){
      b++;
    }
  }

  if(a > 0 && b > 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
