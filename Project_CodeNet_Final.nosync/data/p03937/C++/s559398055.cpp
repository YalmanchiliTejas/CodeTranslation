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
typedef vector<vector<ll>> Graph;
typedef vector<pii> vpii;

int main() {
  ll H,W; cin>>H>>W;
  vector<string> v(H); REP(i,H) cin>>v[i];
  ll cnt=0;
  REP(i,H) REP(j,W) if(v[i][j]=='#') cnt++;
  if(cnt==H+W-1) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
