#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  string S;
  char C;

  cin >> N;
  cin >> S;
  cin >> K;

  C = S.at(K-1);

  for(int i=0;i<N;i++){
    if(S.at(i)!=C){
      cout << "*";
    }else{
      cout << S.at(i);
    }
  }
}
