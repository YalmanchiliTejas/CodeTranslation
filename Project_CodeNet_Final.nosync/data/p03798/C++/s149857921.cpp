#include<bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;

char dp[100002];
int n;
string s;

bool check() {
  rep(i, 2, n+2) {
    if (dp[i-2]=='S') {
      if (dp[i-1]=='S') {
		if (s[i-1]=='o') dp[i]='S';
		else dp[i] = 'W';
	  }
      else {
        if (s[i-1]=='o') dp[i]='W';
        else dp[i]='S';
      }
    }
    else {
      if (dp[i-1]=='S') {
        if (s[i-1]=='o') dp[i]='W';
        else dp[i]='S';
      }
      else {
        if (s[i-1]=='o') dp[i]='S';
        else dp[i]='W';
      }
    }
  }
  if (dp[0]==dp[n]&&dp[1]==dp[n+1]) return true;
  else return false;
}

int main() {
  cin>>n>>s;
  s+=s[0];
  s+=s[1];
  dp[0]='S';
  dp[1]='S';
  if (check()) {
    rep(i, 0, n) cout << dp[i];
    cout << endl;
    return 0;
  }
  dp[0]='S';
  dp[1]='W';
  if (check()) {
    rep(i, 0, n) cout<<dp[i];
    cout<<endl;
    return 0;
  }
  dp[0]='W';
  dp[1] = 'S';
  if (check()) {
    rep(i, 0, n) cout<<dp[i];
    cout<<endl;
    return 0;
  }
  dp[0]='W';
  dp[1]='W';
  if (check()) {
    rep(i, 0, n) cout<<dp[i];
    cout<<endl;
    return 0;
  }
  cout<<-1<<endl;
  return 0;
}
