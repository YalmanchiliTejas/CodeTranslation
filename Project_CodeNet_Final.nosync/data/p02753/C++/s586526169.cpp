#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
  string S;
  cin >> S;
  bool bus = false;
  if(S.at(0) != S.at(1)) bus = true;
  if(S.at(1) != S.at(2)) bus = true;
  if(S.at(2) != S.at(0)) bus = true;
  puts(bus ? "Yes" : "No");
}
