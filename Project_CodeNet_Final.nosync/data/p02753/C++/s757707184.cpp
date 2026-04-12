//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
private:
  ll *fac,*finv,*inv;
public:
  Comb(){
    fac = new ll[1000000];
    finv = new ll[1000000];
    inv = new ll[1000000];
    fac[0] = 1;
    for(int i=1;i<1000000;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000000;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000000;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

int main(){
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]){
    cout << "No" << endl;
  }
  else cout << "Yes" << endl;
  return 0;
}
