#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll solve(string s,ll k){
  ll n=s.size();
  ll m=0;
  if(k==1){
    m+=(n-1)*9;
    ll b=s[0]-'0';
    m+=b;
  }
  else if(k==2){
    if(n<=1){
      return 0;
    }
    m+=(n-1)*(n-2)/2*9*9;
    ll b=s[0]-'0';
    m+=(b-1)*(n-1)*9;
    ll c=1;
    while(c<n-1){
      if(s[c]!='0')break;
      c++;
    }
    string t=s.substr(c);
    m+=solve(t,1);
  }
  else{
    if(n<=2){
      return 0;
    }
    m+=(n-1)*(n-2)*(n-3)/6*9*9*9;
    ll b=s[0]-'0';
    m+=(b-1)*(n-1)*(n-2)/2*9*9;
    ll c=1;
    while(c<n-1){
      if(s[c]!='0')break;
      c++;
    }
    string t=s.substr(c);
    m+=solve(t,2);
  }
  return m;
}


int main(){

  string s;
  ll k;
  cin >> s >> k;
  // ll n=s.size();

  // ll m=0;

  // ll a=0;
  // ll b=1;
  // while(a<k){
  //   b*=(n-a);
  //   a++;
  // }
  // while(a>0){
  //   b/=a;
  //   a--;
  // }

  // m+=b*pow(9,k);

  // if(k==1){
  //   ll c=s[0];
  //   m+=c;
  // }
  // else if(k==2){
  //   if(n<=1){
  //     cout << 0 << endl;
  //     return 0;
  //   }
  //   ll c=s[0];
  //   ll d=s[1];
  //   m+=(c-1)*9*(n-1);
  //   m+=9*(n-2)+d;
  // }
  // else{
  //   if(n<=2){
  //     cout << 0 << endl;
  //     return 0;
  //   }
  //   ll c=s[0],d=s[1],e=s[2];
  //   m+=(c-1)*(n-1)*(n-2)/2*9*9;
  //   m+=(d-1);
  // }

  cout << solve(s,k) << endl;



}