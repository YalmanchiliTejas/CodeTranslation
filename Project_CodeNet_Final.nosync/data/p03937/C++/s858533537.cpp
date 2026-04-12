#include <bits/stdc++.h>
using namespace std;


int main() {
  int h,w;
  cin >> h>>w;
  int sum=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char a;
      cin >> a;
      if(a=='#'){
        sum++;
      }
    }
  }
  cout <<  ( sum == h+w-1?"Possible":"Impossible");
    
}