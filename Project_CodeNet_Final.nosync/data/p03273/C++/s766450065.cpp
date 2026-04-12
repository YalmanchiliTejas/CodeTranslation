#include "bits/stdc++.h"
#define ll long long
#define inf 1000000007 //10^9+
#define sort(vec) sort(vec.begin(),vec.end());
#define rever(vec) reverse(vec.begin(),vec.end());
#define unsort(vec) sort(vec); rever(vec);
#define gcd __gcd
using namespace std;

int main() {
  ll H,W;
  cin>>H>>W;
  char tab[H][W];
  bool high=true;
  bool side=true;
  ll will=0;
  for(ll i=0;i<H;i++) {
    for(ll j=0;j<W;j++) {
      char a;
      cin>>a;
      tab[i][j]=a;
    }
  }
  for(ll i=0;i<H;i++) {
    for(ll j=0;j<W;j++) {
      if(tab[i][j]!='.') {
        high=false;
        break;
      }
    }
    if(high) {
      for(ll j=0;j<W;j++) {
        tab[i][j]='0';
      }
    }
    high=true;
  }
  for(ll i=0;i<W;i++) {
    for(ll j=0;j<H;j++) {
      if(tab[j][i]=='#') {
        side=false;
        break;
      }
    }
    if(side) {
      for(ll j=0;j<H;j++) {
        tab[j][i]='0';
      }
    }
    side=true;
  }
  for(ll i=0;i<H;i++) {
    for(ll j=0;j<W;j++) {
      if(tab[i][j]!='0'){
        cout<<tab[i][j];
      }
      else {
        will++;
      }
    }
    if(will!=W) {
      cout<<endl;
    }
    will=0;
  }
}