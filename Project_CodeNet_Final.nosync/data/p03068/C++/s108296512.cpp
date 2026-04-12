#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int N,K;
  string S,T;
  char t;
  cin >> N >> S >> K;
  T=S;
  t=S.at(K-1);
  for (int i=0; i<N ;i++){
    if(S.at(i)==t){
      T.at(i)=S.at(i);
    }
    else{
      T.at(i)='*';
    }
  }
  cout << T << endl;
}