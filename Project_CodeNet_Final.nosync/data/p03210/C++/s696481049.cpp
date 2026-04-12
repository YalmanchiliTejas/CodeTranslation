#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N;
  string ans = "NO";
  cin >>N;

  if(N == 7 || N == 5 || N == 3)ans = "YES";

  cout <<ans<<endl;
  return 0;
}
