#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll k[50][30];
ll p[26];
int main(){
  ll n;
  cin>> n;
  string s[n];
  for(ll i=0;i<n;i++) {
    cin >>s[i];
    sort(s[i].begin(),s[i].end());
    ll ss=s[i].size();
    for(ll j=0;j<ss;j++) k[i][s[i][j]-'0'-49]++;
  }
  for(ll i=0;i<26;i++){
    ll mi=100;
    for(ll j=0;j<n;j++){
      mi=min(k[j][i],mi);
    }
    p[i]=mi;
    
  }
  for(ll i=0;i<26;i++){
    string l;
    l+='a'+i;
    for(ll j=0;j<p[i];j++) cout <<l;
  }
  cout <<endl;
}
