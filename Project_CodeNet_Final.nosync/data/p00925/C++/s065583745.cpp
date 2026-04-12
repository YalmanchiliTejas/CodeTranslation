#include <bits/stdc++.h>
using namespace std;
int eval1(string S){
  int N = S.size();
  int ans = 0;
  int p = 1;
  for (int i = 0; i < N; i++){
    if (S[i] == '+'){
      ans += p;
      p = 1;
    } else if (S[i] != '*'){
      p *= S[i] - '0';
    }
  }
  ans += p;
  return ans;
}
int eval2(string S){
  int ans = 0;
  int N = S.size();
  ans = S[0] - '0';
  for (int i = 1; i < N; i += 2){
    if (S[i] == '+'){
      ans += S[i + 1] - '0';
    } else {
      ans *= S[i + 1] - '0';
    }
  }
  return ans;
}
int main(){
  string S;
  cin >> S;
  int N;
  cin >> N;
  int M = eval1(S);
  int L = eval2(S);
  if (M == N){
    if (L == N){
      cout << 'U' << endl;
    } else {
      cout << 'M' << endl;
    }
  } else {
    if (L == N){
      cout << 'L' << endl;
    } else {
      cout << 'I' << endl;
    }
  }
}
