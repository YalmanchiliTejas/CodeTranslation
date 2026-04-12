#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  ll N, X, M;
  cin >> N >> X >> M;

  vector<ll> tmp(M);
  tmp[0] = X;
  ll sum = 0;
  map<int, int> m;
  m[tmp[0]] = 0;
  ll loop_s = 0;
  ll loop_e = 0;

  for(int i = 1; i < N; i++){
    tmp[i] = tmp[i - 1] * tmp[i - 1] % M;
    if(m.find(tmp[i]) != m.end()){
      loop_s = m[tmp[i]];
      loop_e = i;
      break;
    }else{
      m[tmp[i]] = i;
    }
  }

  if(loop_e == 0){
    for(int i = 0; i < N; i++){
      sum += tmp[i];
    }
  }else{
    for(int i = 0; i < loop_s; i++){
      sum += tmp[i];
    }
    ll tmpsum = 0;
    for(int i = loop_s; i < loop_e; i++){
      tmpsum += tmp[i];
    }
    sum += tmpsum * ((N - loop_s) / (loop_e - loop_s));
    for(int i = loop_s; i < loop_s + (N - loop_s) % (loop_e - loop_s); i++){
      sum += tmp[i];
    }
  }
  cout << sum << endl;
}