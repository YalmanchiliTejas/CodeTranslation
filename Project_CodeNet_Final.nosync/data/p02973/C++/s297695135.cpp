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
    // 後ろから見ていった時に、a[i]以上の大きさの最初の要素のiterator
    auto it = lower_bound(dp.rbegin(), dp.rend(), a[i]);
    // a[i]よりも大きい値はなかったので末尾に追加する
    if(it == dp.rbegin()) dp.push_back(a[i]);
    else {
      // a[i]以上の大きさの値が見つかったので、「そのイテレータの一つ前の要素と入れ替える」
      // a[i]以上の最初の要素の一つ前、ということはa[i]未満の要素ということ、
      // a[i]未満なのでその単調増加数列はa[i]を末尾に追加可能
      it--;
      *it = a[i];
    }

//rep(i, dp.size()) cout<<dp[i]<<' ';cout<<endl;
  }

//rep(i, dp.size()) cout<<dp[i]<<' ';cout<<endl;

  cout<<dp.size()<<endl;

  return 0;
}
