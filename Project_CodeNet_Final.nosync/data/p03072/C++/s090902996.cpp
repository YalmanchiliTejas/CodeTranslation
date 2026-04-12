#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define mod 1000000007


int main(){
  ll n;
  ll h[110]={0};
  ll ma[110]={0};
  cin >>n;
  ll res=0;
  rep(i,n){
    cin >> h[i];
    res=max(res,h[i]);
    ma[i]=h[i];
  }
  ll ans=0;
  rep(i,n){
    bool flag=true;
    rep(j,i){
      if(h[i]<ma[j]){
        flag=false;
      }
    }
    if(flag)ans++;
  }
  cout << ans << endl;
}
