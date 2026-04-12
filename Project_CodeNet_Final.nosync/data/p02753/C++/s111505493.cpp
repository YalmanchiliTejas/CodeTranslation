#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  int st1, st2, st3;
  cin >> S;
  st1 = S[0];
  st2 = S[1];
  st3 = S[2];
  if(S[0] == S[1] && S[1] == S[2]){
    cout << "No" << endl;

  }else {
    cout << "Yes" << endl;
  }
}
