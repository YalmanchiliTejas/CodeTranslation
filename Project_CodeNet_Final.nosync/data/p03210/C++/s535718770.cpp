#include <bits/stdc++.h> 
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(vec) vec.begin(), vec.end()
typedef long long ll;ll MM = 1000000000;ll mod = MM + 7;
ll GCD(ll x, ll y) {if (x % y == 0) return y;else return GCD(y, x % y);}
ll LCM(ll x, ll y) { return x * y / GCD(x, y);}

int main(){
  ll x; cin>>x;
  if(x==7||x==5||x==3) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
  
  
}