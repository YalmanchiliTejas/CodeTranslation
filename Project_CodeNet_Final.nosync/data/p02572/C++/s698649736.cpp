#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;


int main(){
  ll con = 1000000007;
  int n;
  cin>>n;
  vector <ll> a(n);
  ll cnt = 0;
  ll ans=0;
  rep(i,n) {
    cin>>a[i];
    cnt+=a[i];
  }


  rep(i,n-1){
    cnt-=a[i];
    ans+=(cnt%con)*a[i];
    ans%=con;
  }
  cout<<ans;

}