#include<bits/stdc++.h>

using namespace std;

int main(){
  int x = 0;
  int y = 0;
  char S[3];
  cin >> S;
  int i;
  for(i=0;i<=2;i++){
    if(S[i]=='A') x = 1;
    if(S[i]=='B') y = 1;
    }
  if(x * y == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}