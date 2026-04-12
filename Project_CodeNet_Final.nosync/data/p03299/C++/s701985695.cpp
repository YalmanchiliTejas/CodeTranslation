#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<int, P> Pint;
const ll MOD=1e9+7;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k>0){
        if(k%2==1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k/=2;
    }
    return ans;
}
int main()
{
	
	int n;
  ll h[101];
  vector<ll> hs;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>h[i]; hs.push_back(h[i]);
  }
  sort(hs.begin(), hs.end());
  hs.erase(unique(hs.begin(), hs.end()), hs.end());
  ll dp[2][100][100]={};
  vector<Pint> v;
  for(int i=hs.size()-1; i>=0; i--){
    bool nuo[102]={}, nuo2[102]={};
    for(int j=1; j<=n; j++){
      if(hs[i]<=h[j]) nuo[j]=1;
    }
    int l;
    for(int j=0; j<=n; j++){
      if(!nuo[j] && nuo[j+1]) l=j;
      if(nuo[j] && !nuo[j+1]){
        bool ok=0;
        for(int k=l+1; k<=j; k++){
          if(hs[i]==h[k]){
            ok=1;
            break;
          }
        }
        if(ok) v.push_back(Pint(hs[i], P(l+1, j)));
      }
    }
  }
  bool used[100]={};
  for(int i=0; i<v.size(); i++){
    int l=v[i].second.first, r=v[i].second.second, d0=v[i].first;
    //cout<<l<<" "<<r<<" "<<d0<<endl;
    bool no=1;
    dp[1][l][r]=2;
    ll prod=1, prod1=1;
    int ct=0;
    bool nuo=0;
    int ct2=0;
    for(int j=0; j<i; j++){
      int l1=v[j].second.first, r1=v[j].second.second;
      if(l>l1 || r1>r) continue;
      if(used[j]) continue;
      used[j]=1;
      no=0;
      if(r1!=l1) nuo=1;
      int d1=v[j].first;
      dp[1][l][r]*=(dp[1][l1][r1]*powmod(2ll, d1-d0-1)%MOD);
      dp[1][l][r]%=MOD;
      prod*=(dp[0][l1][r1]+dp[1][l1][r1]*powmod(2ll, d1-d0)%MOD);
      prod%=MOD;
      prod1*=(dp[1][l1][r1]*powmod(2ll, d1-d0)%MOD);
      prod1%=MOD;
      ct+=(r1-l1+1);
      ct2++;
    }
    if(no){
      dp[0][l][r]=(powmod(2ll, r-l+1)-2+MOD)%MOD;
    }else{
      if(nuo) dp[0][l][r]=((prod-prod1+MOD)*powmod(2ll, r-l+1-ct)%MOD+dp[1][l][r]*500000004%MOD*(powmod(2ll, r-l+1-ct+ct2)+MOD-2)%MOD)%MOD;
      else dp[0][l][r]=dp[1][l][r]*500000004%MOD*(powmod(2ll, r-l+1)+MOD-2)%MOD;
    }
    if(r-l+1==n){
      ll ans=dp[0][l][r]+dp[1][l][r]*powmod(2ll, d0-1)%MOD;
      ans%=MOD;
      cout<<ans<<endl;
    }
  }
	return 0;
}