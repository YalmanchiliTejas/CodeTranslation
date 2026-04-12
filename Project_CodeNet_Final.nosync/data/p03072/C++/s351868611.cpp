#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, i;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  
  int sum = 1;
  int max = v[0];
  
  for(i = 1; i < N; i++){
    if(max <= v[i]){
      sum += 1;
      max = v[i];
    }
  }
  cout << sum << endl;
  return 0;
}