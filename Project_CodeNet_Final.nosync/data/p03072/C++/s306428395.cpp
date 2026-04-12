#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b?a:b;}
ll min(ll a, ll b) {return a<b?a:b;}


int main(void) {
  ll N;
  cin >> N;
  
  ll max=0;
  ll ans=0;
  
  for(ll i=0; i<N; i++) {
    ll h;
    cin >> h;
    chmax(max, h);
    if(max<=h) ans++;
  }
  
  pt(ans);
}










