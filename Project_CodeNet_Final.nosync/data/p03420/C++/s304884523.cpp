#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  ll n,k; cin>>n>>k;
  ll an=0;
  for(ll b=k+1;b<=n;b++) {
    for(ll u=0;u<=n;u+=b) {
      ll pl = min(n, u + b-1) - (u + k - 1);
      pl = max(0LL, pl);
      if (k == 0 && u == 0) pl--;
      //cout<<b<<" "<<u<<"  "<<u+b-1<<" "<<u+k<<" "<<pl<<endl;
      an += pl;
    }
  }
  cout<<an<<endl;
}
