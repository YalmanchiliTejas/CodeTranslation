#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  string S;
  cin >> N >> S >> K;
  for (int i = 1;i <= N;i++){
    if(S.at(K-1)!=S.at(i-1))S.at(i-1)='*';
  }
  cout << S<< endl;
}