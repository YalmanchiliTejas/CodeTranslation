#include <bits/stdc++.h>
using namespace std;

int main()
  {
  int N;
  cin >> N;
  vector <int> H(N); 
  for(int num=0; num<N; ++num){
    cin >> H[num];
      }
  
  int k=0;
  
  for(int num=0; num<N; ++num){
    bool s = true;
      for (int t = 0; num>t; ++t){
        if (H[t]>H[num]){
          s = false;
          break;
          }}
        if (s){
          ++k;}}
    
  cout << k <<endl;
  
  return 0;
  }
    