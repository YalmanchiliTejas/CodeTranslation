#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, a, b, c, d, e, g;
  int X, M,j, f, l;
  a = 0;
  c = 0;
  e = 0;
  f = 0;
  cin >> N >> X >> M;
  vector<long long> v(M + 1);
  v.at(0) = X;
  for (int i = 0;i < M; i++){
    v.at(i + 1) =  (v.at(i) * v.at(i)) % M;
  }
  for (int i = 0;i < M + 1; i++){
    j = i;
    for (int k = 0;k < i; k++){
      l = k;
      if (v.at(i) == v.at(k)){
        f = 1;
        break;
      }
    }
    if (f == 1){
      break;
    }
  }
  g = j - l;
  if (v.at(M) == 0){
    for (int i = 0;i < M; i++){
      j = i;
      if (v.at(i) == 0){
        break;
      }
    }
    for (int i = 0;i < j; i++){
      a += v.at(i);
    }
    cout << a << endl;
  }
    
  else if (j >= N){
  for (int i = 0;i < N; i++){
    a += v.at(i);
  }
  cout << a << endl;
  }
  else{
    for (int i = l;i < j; i++){
      a += v.at(i);
    }
    b = (N  - l) % g;
    for (int i = l;i < l + b; i++){
      c += v.at(i);
    }
    d = (N - l) / g;
    for (int i = 0;i < l; i++){
      e += v.at(i);
    }
    cout << a * d + c + e << endl;
  }
}