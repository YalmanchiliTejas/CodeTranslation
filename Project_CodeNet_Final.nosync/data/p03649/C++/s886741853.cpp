#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define ALL(a) (a).begin(),(a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;
struct Edge{ll s,t,d; Edge(ll s,ll t,ll d):s(s),t(t),d(d){}};
typedef vector<vector<Edge>> Graph;
typedef vector<pii> vpii;

int main() {
  ll N; cin>>N;
  vi a(N); REP(i,N) cin>>a[i];
  ll asum=0; REP(i,N) asum+=a[i];
  ll x=max(0ll,asum-N*N);
  while(1) {
    ll y=0;
    REP(i,N) y+=(x+1+a[i])/(N+1);
    if(y<=x) {cout<<x<<endl; return 0;}
    x++;
  }
}
