#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  bool ans = false;
  
  for(int i=0; i<2; i++){
    if(S[i] != S[i+1]){
      ans = true;
    }
  }
  
  if(ans == true){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}

    