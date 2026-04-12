#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dlp(int i){
  ll k=1;
  for(int j=0;j<i;j++)
    k*=2;
  return k;
}

ll bg[50];
ll p=0;

void bgw(ll x,int n){
  x--; if(!x) return;
  if(x<bg[n-1]*2-1){
    bgw(x,n-1);
    return;
  }
  x-=(bg[n-1]*2-1); p+=bg[n-1]; if(!x) return;
  x--; p++; if(!x) return;
  if(x<bg[n-1]*2-1){
    bgw(x,n-1);
    return;
  }
  x-=(bg[n-1]*2-1); p+=bg[n-1]; if(!x) return;
  x--; return;
}

int main(){
  int X; cin>>X;
  for(int i=0;i<X;i++){
    bg[i]=dlp(i+1)-1; //バンズも含める時はbg[i]*2-1
  }
  ll N; cin>>N;
  bgw(N,X);
  cout<<p<<endl;
}