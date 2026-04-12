#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


int main(void) {
  ll N;
  cin >> N;
  ll a[MAX];
  ll i;
  
  priority_queue<P> q;
  for(i=0; i<N; i++) {
    cin >> a[i];
  }
  
  ll clr=0;
  vector<ll> v;
  v.push_back(a[N-1]);
  for(i=N-2; i>=0; i--) {
    ll len=v.size();
    
    if(v[len-1]<=a[i]) {
      v.push_back(a[i]);
    }else {
      ll itr=upper_bound(v.begin(), v.end(), a[i])-v.begin();
      v[itr]=a[i];
    }
    
  }
  
  pt(v.size());
  
}
