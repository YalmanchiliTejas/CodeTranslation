#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,p=1000000007;
  cin >> n;
  vector<ll> a(n);
  ll i,s,t;
  s=0;
  t=0;
  for(i=0;i<n;i++){
    cin >> a.at(i);
    s += a.at(i);
    s %= p;
    t += a.at(i)*a.at(i);
    t %= p;
  }
  s=s*s%p;
  if(s>=t){
    s -= t;
  }else{
    s=s-t+p;
  }
  if(s%2==0){
    cout << s/2 << endl;
  }else{
    cout << (s+p)/2 << endl;
  }
}