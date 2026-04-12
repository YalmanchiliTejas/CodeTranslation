#include<bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, X;

lint rec(lint N, lint X){
  if(N == 0) return 1;
  if(X == 1) return 0;
  lint len = (1LL << N + 1)  - 3;
  lint p =  (1LL << N) - 1;
  if(1 < X && X <= 1 + len) return rec(N - 1, X - 1);
  if(X == 2 + len) return p + 1;
  if(2 + len <= X && X <= 2 * len + 2) return p + 1 + rec(N - 1, X - len - 2);
  if(X == 2 * len + 3) return 2 * p + 1;
}

signed main(){
  cin >> N >> X;
  cout << rec(N, X) << endl;
}