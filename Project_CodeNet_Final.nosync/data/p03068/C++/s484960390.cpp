#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
  ll n,k;
  char s[20];
  cin >> n >> s >> k;
  k--;
  for(int i=0;i<n;i++){
    if(s[i]!=s[k])s[i]='*';
  }
  cout << s;
}