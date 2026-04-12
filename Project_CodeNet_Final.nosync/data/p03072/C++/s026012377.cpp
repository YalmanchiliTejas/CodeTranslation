#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n) cin >> h[i];
  
  int max = 0;
  int num = 0;
  rep(i,n){
    if(h[i]>=max){
      max = h[i];
      num++;
    }
  }
  
  cout << num << endl;
  return 0;
}
