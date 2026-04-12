#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n; cin>>n;
  P x[n]; for(int i=0;i<n;i++) {
    cin>>x[i].first; x[i].second=i;
  }
  sort(x,x+n);
  int an[n];
  for(int i=0;i<n;i++) {
    if (i < n/2) {
      an[x[i].second] = x[n/2].first;
    } else {
      an[x[i].second] = x[n/2-1].first;
    }
  }
  for(int i=0;i<n;i++) {
    cout<<an[i]<<endl;
  }
}