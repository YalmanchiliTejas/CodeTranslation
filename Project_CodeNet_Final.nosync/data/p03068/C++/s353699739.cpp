#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int n ;
  cin >> n ;
  string s ;
  cin >> s ;
  int k ;
  cin >> k ;
  
  
  string a ;
  for(int i=0;i<n ;i++){
    if(s.at(i)!=s.at(k-1)){
      a+='*';
    }
    else{
      a+=s.at(i);
    }
  }
  
  cout << a <<endl;
}