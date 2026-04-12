#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long
const double EPS = 1e-10;
const ll MOD = 7+(1e+9);

int main(){
  ll n;
  cin>>n;
  vector<ll>v(n,0);
  for(ll i=0;i<n;i++){
    cin>>v[i];
  }
  ll ans=1;
  for(ll i=1;i<n;i++){
    ll f=0;
    for(ll j=0;j<i;j++){
      if(v[i]<v[j])f++;
    }
    if(f==0)ans++;
  }
  cout<<ans<<endl;
}
