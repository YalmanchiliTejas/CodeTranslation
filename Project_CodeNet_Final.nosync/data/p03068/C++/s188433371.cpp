#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n,k;
  string s;
  cin >>n;
  cin >>s;
  cin >>k;
  for(ll i=0;i<n;i++){
    if(s[i]!=s[k-1]) cout <<"*";
    else cout <<s[i];
  }
  cout <<endl;
}
