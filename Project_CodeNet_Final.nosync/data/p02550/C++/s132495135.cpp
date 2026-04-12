#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int GCD(int x,int y){
  if(x<y){
    swap(x,y);
  }
  while(x%y!=0){
    int temp=x;
    x=y;
    y=temp%y;
  }
  return y;
}

int digitsum(int x){
  int sum=0;
  while(x>0){
    sum+=(x%10);
    x/=10;
  }
  return sum;
}

int main() {
  ll n,x,m;
  cin>>n>>x>>m;
  set<int> memo;
  vector<int> p;
  ll now=x;
  int a,b;
  bool check=false;
  for(int i=0;i<n;i++){
    if(i==0){
      p.push_back(x);
      memo.insert(x);
      continue;
    }
    now=mod(now*now,m);
    if(memo.count(now)){
      check=true;
      for(int j=0;j<p.size();j++){
        if(p[j]==now){
          a=j;
          b=i-1;
        }
      }
      break;
    }
    else{
      p.push_back(now);
      memo.insert(now);
    }
  }
  if(!check){
    ll ans=0;
    for(int i=0;i<p.size();i++){
      ans+=p[i];
    }
    cout<<ans<<endl;
    return 0;
  }
  ll ans=0;
  for(int i=0;i<a;i++){
    ans+=p[i];
  }
  ll temp=0;
  for(int i=a;i<=b;i++){
    temp+=p[i];
  }
  ll shuuki=b-a+1,kuri=(n-a)/shuuki,amari=(n-a)%shuuki;
  for(int i=0;i<amari;i++){
    ans+=p[a+i];
  }
  ans+=temp*kuri;
  cout<<ans<<endl;
  return 0;
}