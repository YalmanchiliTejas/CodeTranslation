#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[3];
  bool ans = true;
  scanf("%s",S);
  if(S[0] == S[1] && S[1] == S[2])
    ans = false;
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
