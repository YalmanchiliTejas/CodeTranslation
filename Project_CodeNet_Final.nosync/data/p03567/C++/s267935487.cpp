#include <bits/stdc++.h>
using namespace std;


int main(){
  string S;
  cin >> S;
  for(int ii=0; ii<S.size()-1; ii++){
    if(S[ii]=='A'&&S[ii+1]=='C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
