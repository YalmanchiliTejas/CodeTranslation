#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N; cin>>N;
  vector<ll> A(N);
  rep(i,N)cin>>A.at(i);
  vector<ll> res;
  res.push_back(A.at(N-1));
  for(int i = N-2; i >= 0; i--){
    //sort(begin(res),end(res));
    auto iter = upper_bound(begin(res),end(res),A.at(i));
    ll dist = distance(begin(res),iter);
    if(dist==(ll)res.size()){
      res.push_back(A.at(i));
    }else{
      res.at(dist) = A.at(i);
    }
  }
  cout<<res.size()<<endl;
}














