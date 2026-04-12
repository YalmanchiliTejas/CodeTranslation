#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return a % 1000000007;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll n; cin >> n; ll maxhigh = 0; ll count = 0;
  
  for(ll i=0; i < n; i++){
	ll h; cin >> h;
    if(h >= maxhigh){
      maxhigh = h;
      count++;
    }
    
  }
  
  cout << count << endl;
}