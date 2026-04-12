#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a,b;

ll f(ll n, ll x){
  if(n == 0){
    return 1;
  }else if(x == 0){
    return 0;
  }if(x < a[n-1] + 1){
    return f(n-1, x-1);
  }else if(x == a[n-1] + 1){
    return b[n-1] + 1;
  }else{
    return b[n-1] + 1 + f(n-1, x - a[n-1] - 2);
  }
}
    

int main(){
  
  ll n,x;
  cin >> n >> x;
  
  a.push_back(1);
  b.push_back(1);
  for(int i=1; i<=n; i++){
    a.push_back(2 * a[i-1] + 3);
    b.push_back(2 * b[i-1] + 1);
  }
  
  cout << f(n, --x) << endl;
}