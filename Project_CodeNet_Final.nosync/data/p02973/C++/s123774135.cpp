#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

int main(){
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N) cin >> A[i];

  vll ma;
  rep(i, N){
    auto ub = upper_bound(ma.begin(), ma.end(), -A[i]);
    if(ub == ma.end()) ma.push_back(-A[i]);
    else *ub = -A[i];
  }
  cout << ma.size() << endl;
  return 0;
}
