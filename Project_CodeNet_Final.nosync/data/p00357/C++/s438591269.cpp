#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i,n) cin >> d[i];
  int a = 10;
  rep(i,n){
    a -= 10;
    if(a < 0){
      cout << "no" << endl;
      return 0;
    }
    a = max(a,d[i]);
  }
  a = 10;
  reverse(d,d+n);
  rep(i,n){
    a -= 10;
    if(a<0){
      cout << "no" << endl;
      return 0;
    }
    a = max(a,d[i]);
  }
  cout << "yes" << endl;
  return 0;
}

