#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);i++)
using namespace std;


int main(){
  string S;
  cin >> S;
  string ans;
  if(S=="AAA") ans = "No";
  if(S=="BAA") ans = "Yes";
  if(S=="ABA") ans = "Yes";
  if(S=="AAB") ans = "Yes";
  if(S=="BBA") ans = "Yes";
  if(S=="BAB") ans = "Yes";
  if(S=="ABB") ans = "Yes";
  if(S=="BBB") ans = "No";
  cout << ans << endl;
}