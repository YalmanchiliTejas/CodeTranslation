#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n); ++i)
using namespace std;

int main(){

  char c;
  
  cin >> c;
  
  if( c == 'a' || c == 'i' || c == 'e' || c == 'u' || c == 'o' ){
    cout << "vowel";
  }else{
    cout << "consonant";
  }
    
    return 0;
}
