#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  
  char a = S.at(K - 1);
  
  for(char &i: S){
    if(i != a)
      i ='*';
  }
  
  cout << S << endl;
}
