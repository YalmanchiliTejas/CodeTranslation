#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
  int N,K;
  string S;
  cin >> N >> S >> K;
  char X = S.at(K - 1);
  for( int i = 0;i < N;i++){
      if(S.at(i) != X){
          S.at(i) = '*';
      }
  }
  cout << S << endl;
}
