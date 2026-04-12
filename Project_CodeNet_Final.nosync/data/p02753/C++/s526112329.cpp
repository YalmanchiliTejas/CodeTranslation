#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  int j=0;
  cin >> S;
 
  for(int i=0;i<3;i++){
    if(S.at(i) == 'A'){
        j++;
    }else{
        j--;
    }
  }
  
  if(j==3||j==-3){
      cout << "No" << endl;
  }else{
      cout << "Yes" << endl;
  }
  
}