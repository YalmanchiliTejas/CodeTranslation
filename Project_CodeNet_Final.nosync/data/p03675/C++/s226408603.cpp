#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define US unordered_set
#define ALL(a) (a).begin(),(a).end()
const ll INF = (1ll << 60);

int main() {
  list<ll> l;
  ll n; cin>>n;
  REP(i,n) {
    ll a; cin>>a;
    if(i%2==0) l.PB(a);
    else l.push_front(a);
  }

  list<ll> ll;
  if(n%2) for(auto i:l) ll.push_front(i);
  else for(auto i:l) ll.push_back(i);

  l=ll;

  for(auto it=l.begin();it!=l.end();++it) {
    if(next(it)==l.end()) cout<<*it<<endl;
    else cout<<*it<<' ';
  }

}
