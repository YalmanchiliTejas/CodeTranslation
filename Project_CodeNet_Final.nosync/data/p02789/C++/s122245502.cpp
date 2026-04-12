#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main() {
  int a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}