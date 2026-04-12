#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
using namespace std;

int N;
vector<ll> S;

int main(){
  cin>>N;
  S.resize(N);
  for(int i=0;i<N;i++) cin>>S[i];

  ll ans=0;
  for(int C=1;C<=N-1;C++){
    ll score=0;
    vector<bool> used(N,false);
    for(int x=0;x*C<N-1;x++){
      if((N-1)-x*C<=C) break;
      if(used[x*C]) break;
      used[x*C]=true;

      if(used[(N-1)-x*C]) break;
      used[(N-1)-x*C]=true;

      score+=S[x*C];
      score+=S[(N-1)-x*C];
      ans=max(ans,score);
    }
  }

  cout<<ans<<endl;

  return 0;
}
