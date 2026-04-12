#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

#define MOD 1000000007


int main(){

  ll n,sum=0;
  cin >> n;

  std::vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
    sum+=a.at(i);

  }


ll tsum=0;
  for(ll i=0;i<n;i++){



      tsum+=(a.at(i)%MOD)*((sum-a.at(i))%MOD)%MOD;

      sum-=a.at(i);
  }



  cout << tsum%MOD << endl;


  }
