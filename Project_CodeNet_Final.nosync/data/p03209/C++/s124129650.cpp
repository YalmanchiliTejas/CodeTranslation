#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<pair<ll,ll>>>;

ll N,X;
vector<ll> P;
vector<ll> A;

ll f(ll level, ll x){
  if(level==0)return 1;
  if(x==A.at(level))return P.at(level);
  else if(A.at(level-1)+3<=x&&x<=A.at(level)-1){
    return P.at(level-1)+1+f(level-1,x-2-A.at(level-1));
  }else if(x==A.at(level-1)+2)return P.at(level-1)+1;
  else if(x>1)return f(level-1,x-1);
  else return 0;
}

int main(){
  cin>>N>>X;
  P.resize(N+1,0);
  A.resize(N+1,0);
  P.at(0)=1;
  A.at(0)=1;
  rep1(i,N+1)P.at(i)=2*P.at(i-1)+1;
  rep1(i,N+1)A.at(i)=A.at(i-1)*2+3;
  cout<<f(N,X)<<endl;
}