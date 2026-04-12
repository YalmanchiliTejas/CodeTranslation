#include <bits/stdc++.h>
using namespace std;

enum An {
  T,
  F
};

An M(An a, An b){
  if(a == T && b == T){
    return T;
  }
  if(a == T && b == F){
    return F;
  }
  if(a == F && b == T){
    return T;
  }
  if(a == F && b == F){
    return T;
  }
}

int main(void){
  int N; cin >> N;
  vector<An> P(N);
  for(int i = 0; i < N; i++){
    char c; cin >> c;
    if(c == 'F'){
      P[i] = F;
    }else{
      P[i] = T;
    }
  }
  An current = M(P[0], P[1]);
  for(int i = 2; i < N; i++){
    current = M(current, P[i]);
  }
  if(current == T){
    cout << 'T' << endl;
  }else{
    cout << 'F' << endl;
  }
  return 0;
}

