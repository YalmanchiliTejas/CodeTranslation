#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void){
  string S;
  cin >> S;

  if(S == "AAA" || S == "BBB"){
    cout << "No" << endl;
  }
  
  else{
    cout << "Yes" << endl;
  }
}