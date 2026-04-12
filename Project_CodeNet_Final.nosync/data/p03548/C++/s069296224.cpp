#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll X, Y, Z;
  cin >> X >> Y >> Z;
  int cnt=0;
  for(int i=1;i<X;i++){
    if(X+1>Z+(Y+Z)*i){
      cnt++;
    }
  }
  cout << cnt << endl;
}