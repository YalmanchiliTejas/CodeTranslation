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
  
  for(i=0; i<N; i++) {
    cin >> a[i];
  }
  
  deque<ll> q;
  q.push_front(INF);
  for(i=0; i<N; i++) {
    
    if(a[i]<=q[0]) {
      q.push_front(a[i]);
    }else {
      *(lower_bound(q.begin(), q.end(), a[i])-1)=a[i];
    }
    
  }
  
  pt(q.size()-1);
  
}
