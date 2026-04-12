#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;


int main(){
  ll N;
  cin>>N;
  vector<ll> A(N);
  ll Sum=0;
  rep(i, N){
    cin>>A[i];
    Sum+=A[i];
    Sum%=MOD;
  }
  ll Ans=0;
  rep(i, N){
    ll Rev=MOD+Sum-A[i];
    Rev%=MOD;
    Ans+=A[i]*Rev;
    Ans%=MOD;
  }
  if(Ans%2)Ans+=MOD;
  Ans/=2;
  cout<<Ans<<endl;
}