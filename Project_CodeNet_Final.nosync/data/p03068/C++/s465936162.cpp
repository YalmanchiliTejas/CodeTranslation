#include <bits/stdc++.h>
using namespace std; 

int main(){
  int n , k ; 
  string s; 
  cin>>n>>s>>k ; 
  for(char c : s ){
    if( c != s[k-1] ) cout<<'*'; 
    else cout<<c; 
  }
}