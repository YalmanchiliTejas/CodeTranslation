#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
int op(int a, int b){
  return max(a, b);
}
int e(){
  return -1;
}
int l;
bool f(int x){
  return x < l;
}
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  segtree<int, op, e> S(A);
  for (int i = 0; i < Q; i++){
    int T;
    cin >> T;
    if (T == 1){
      int X, V;
      cin >> X >> V;
      X--;
      S.set(X, V);
    }
    if (T == 2){
      int L, R;
      cin >> L >> R;
      L--;
      cout << S.prod(L, R) << endl;
    }
    if (T == 3){
      int X, V;
      cin >> X >> V;
      X--;
      l = V;
      cout << S.max_right<f>(X) + 1 << endl;
    }
  }
}