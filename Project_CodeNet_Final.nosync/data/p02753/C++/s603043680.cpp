#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
  /*処理系*/
  string S = "";
  cin >> S;
  int si;
  for (si = 0; si < 2; si++)
  {
    if(S[si] != S[si+1])
      break;
  }
  if(si == 2){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
  return 0;
}