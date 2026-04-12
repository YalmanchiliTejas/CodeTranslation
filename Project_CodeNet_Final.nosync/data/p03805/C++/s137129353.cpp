//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,m;cin>>n>>m;
  vvl data(n);
  rep(i,m){
    ll a,b;cin>>a>>b;
    a--;b--;
    data[a].push_back(b);
    data[b].push_back(a);
  }
  ll count=0;
  vector<ll>vec;
  rep(i,n-1)vec.push_back(i+1);
  do{
    bool ok=true;
    ll point=0;
    for(auto x:vec){
      bool part=false;
      rep(j,data[point].size()){
        if(data[point][j]==x)part=true;
      }
      if(part)point=x;
      else ok=false;
    }
    if(ok)count++;
  }while(next_permutation(vec.begin(),vec.end()));
  cout<<count<<endl;
}
    
  