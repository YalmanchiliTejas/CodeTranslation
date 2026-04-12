#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
string S;
  cin >> N >> S;
int K;
  cin >> K;

  char moji;
  moji = S.at(K - 1);
  for(int i = 0;i < N;i++){
  if(S.at(i) == moji) cout << moji;
    else cout << "*";
  }
 
return 0;
  
}