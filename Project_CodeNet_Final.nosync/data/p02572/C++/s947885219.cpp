#include <bits/stdc++.h>
using namespace std;
#define rep(i,i1,n) for(int i=(int)(i1);i<(int)(n);i++)
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int main() {
  ll n;
  cin>>n;
  vector<ll> vec(n);
  ll sumall=0;
  rep(i,0,n){
    cin>>vec.at(i);
    sumall+=vec.at(i);
  }
  
  ll sum=0;
  
  rep(i,0,n){
    sumall-=vec.at(i);
    sum+=vec.at(i)*(sumall%1000000007);
    if(sum>=1000000007){
      sum%=1000000007;
    }
  }
  cout<<sum;
}