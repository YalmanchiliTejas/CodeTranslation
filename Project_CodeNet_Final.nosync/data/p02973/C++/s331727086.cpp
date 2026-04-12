#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> a(n), dp;

  rep(i, n)cin>>a[i];

  rep(i, n){
    // 後ろから見ていった時に、a[i]よりも小さい最初のiterator
    auto it = lower_bound(dp.rbegin(), dp.rend(), a[i]);
    // a[i]よりも小さい値はなかったので末尾に追加する
    if(it == dp.rbegin()) dp.push_back(a[i]);
    else {
      it--;
      *it = a[i];
    }

//rep(i, dp.size()) cout<<dp[i]<<' ';cout<<endl;
  }

//rep(i, dp.size()) cout<<dp[i]<<' ';cout<<endl;

  cout<<dp.size()<<endl;

  return 0;
}