#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int r,g,b, A =0;
  cin >> r >> g >> b;
  A = r*100 + g*10 + b;
  if(A%4 ==0) cout<< "YES" << endl;
  else cout<< "NO" << endl;
  
 
}