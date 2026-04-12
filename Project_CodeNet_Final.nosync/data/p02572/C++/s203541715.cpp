#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;
#define rep(i,n) for (ll i=0;i<(n);i++)
typedef long long ll;
bool aaa[11111111];
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

 
int main() {
  ll n,c,m,w=0,memo=0,memo2=0,sx=0,sy=1,ans=0,gx,gy;
  string ka,ss;
  cin>>n;
  vector<ll> A(n),B(n);
  rep(i,n)cin>>A[i];
  B[n-1]=A[n-1];
  rep(i,n-1){B[n-i-2]=(B[n-i-1]+A[n-i-2])%1000000007;}
  while(w<n-1){
    ans=(ans+(A[w]*B[w+1]))%1000000007;
    w++;
  }
  cout<<ans<<endl;
 
  
  
}