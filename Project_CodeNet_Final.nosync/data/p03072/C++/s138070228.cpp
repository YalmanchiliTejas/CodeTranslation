#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
  int n ;
  cin >> n  ;
  vector<int> h(n) ;
  for(int i=0;i<n;i++){
    cin >> h[i] ;
  }
  int cnd = h[0] ;
  int cnt = 1 ;
  
  for(int i=1;i<n;i++){
    if(h[i]>=cnd){
      cnt++ ;
      cnd = h[i] ;
    }
  }

  cout << cnt << endl ;
  return 0 ;
}