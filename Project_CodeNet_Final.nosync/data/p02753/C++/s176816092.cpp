#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int a = S.find("A") == string::npos;
  int b = S.find("B") == string::npos;
  int flag = 0;
  if(a!=1 && b!=1)flag = 1;
  if(flag == 1)cout << "Yes"<< endl;
  else{cout << "No" <<endl;}
  return 0;
}