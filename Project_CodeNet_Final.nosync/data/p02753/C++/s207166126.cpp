#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, s1, s2, s3;
  cin >> S;
  
  s1 = S[0];
  s2 = S[1];
  s3 = S[2];
  
  if (s1 == s2 && s1 == s3){
  	cout << "No" << endl;
  }
  else {
  	cout << "Yes" << endl;
  } 
}
