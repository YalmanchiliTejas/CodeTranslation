#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<int> Color(N);
  for (int i=0; i<N; i++){
    Color[i] = -1;
  }
  int cnt = 0;
  for (int i=N-1; i>=0; i--){
    if (i == N-1){
      Color[cnt] = A[i];
      cnt++;
    } else{
      // Color の中で最大なのは常に Color[cnt-1]
      // A[i] がどのColor よりも大きかったら(同じ値でも)
      if (A[i] >= Color[cnt-1]){
        Color[cnt] = A[i];
        cnt++;
      } else{
        // A[i]より大きい最小のColor を A[i]と置き換える そうするとColor の大小関係が変わらない
        for (int j=0; j<cnt; j++){
          if (A[i] < Color[j]){
            Color[j] = A[i];
            break;
          }
        }
      }
    }
  }

  printf("%d\n",cnt);
  return 0;
}
