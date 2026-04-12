#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string y = "Yes";
  if(S.at(0) == 'A' && S.at(1) == 'A' && S.at(2) == 'A') y = "No";
  if(S.at(0) == 'B' && S.at(1) == 'B' && S.at(2) == 'B') y = "No";
  cout << y << endl;
}