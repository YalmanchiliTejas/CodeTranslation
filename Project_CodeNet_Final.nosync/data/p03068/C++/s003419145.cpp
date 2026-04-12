#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  int n,k;
  cin >> n >> S >> k;
  char x = S[k-1];
  for(int i = 0;i < n;i++){
    if(S[i] == x)cout << x;
    else cout << "*";
  }
}