#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main() {
  int N;
  string S;
  int K;
  cin>>N >> S >> K;
 
  for(int i = 0; i <N; i++ ) {
    if(S.at(i)!=S.at(K-1)){
  S.at(i)='*';
   }
  }
cout << S<< endl;
}