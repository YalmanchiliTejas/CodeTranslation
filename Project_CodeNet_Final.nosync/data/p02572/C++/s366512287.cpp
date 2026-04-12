#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int exgcd(int a,int b,int &x,int &y){
  while(b){
    int t{a/b};
    swap(a-=t*b, b);
    swap(x-=t*y, y);
  }
  return a;
}
int exgcd(int a,int b){
  int x{1},y{0};
  return exgcd(a,b,x,y);
}
int inverse(int a,int mod){
  int x{1},y{0};
  exgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}

int main(){
  
  int n; cin>>n;
  vector<int> a(n);
  ll s{};
  for(auto &i:a) {
    cin>>i;
    s += i;
  }
  ll sum{};
  for(int i=0; i<n; i++){
    ll b = s - a.at(i);
    b %= MOD;
    sum += (b*a.at(i))%MOD;
    sum %= MOD;
  }
  cout << (sum * inverse(2,MOD))%MOD<<endl;
  
}
