#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

inline bool LT(double a,double b) { return !equals(a,b) && a < b; }
inline bool LTE(double a,double b) { return equals(a,b) || a < b; }

const bool debug = true;

#define MAX 200100
ll N, x[MAX], y[MAX]; // x[i] <= y[i]

inline bool in(ll v ,ll mini,ll maxi) { return mini <= v && v <= maxi; }

bool cmp(int i,int j) { return x[i] < x[j]; }

struct Data {
  ll v;
  int id;
  bool operator < ( const Data & data ) const {
    if( v != data.v ) return v < data.v;
    return id > data.id;
  }
  bool operator > ( const Data & data ) const {
    if( v != data.v ) return v > data.v;
    return id < data.id;
  }
};

void compute(ll mini,ll maxi) {
  ll ans = LLONG_MAX;

  // mini -> R, maxi -> B
  ll Rmax = mini;
  ll Bmin = maxi;
  rep(i,N) {
    if( !( x[i] <= y[i] ) ) swap(x[i],y[i]);
    Rmax = max(Rmax,x[i]);
    Bmin = min(Bmin,y[i]);
  }
  ans = ( Rmax - mini ) * ( maxi - Bmin );

  // mini -> R, maxi -> R
  vector<int> vec(N);
  rep(i,N) vec[i] = i;
  sort(ALL(vec),cmp);
  priority_queue<Data> maxQ;
  priority_queue<Data,vector<Data>,greater<Data> > minQ;
  vector<ll> cur_val(N);
  rep(i,N) {
    cur_val[i] = x[i];
    maxQ.push((Data){x[i],i});
    minQ.push((Data){x[i],i});
  }
  ans = min(ans,(maxi-mini)*(maxQ.top().v-minQ.top().v));
  rep(i,N) {
    cur_val[vec[i]] = y[vec[i]];
    maxQ.push((Data){y[vec[i]],vec[i]});
    minQ.push((Data){y[vec[i]],vec[i]});
    while( !maxQ.empty() && cur_val[maxQ.top().id] != maxQ.top().v ) maxQ.pop();
    while( !minQ.empty() && cur_val[minQ.top().id] != minQ.top().v ) minQ.pop();
    ans = min(ans,(maxi-mini)*(maxQ.top().v-minQ.top().v));
  }
  cout << ans << endl;
}

int main() {
  cin >> N;
  ll mini = LLONG_MAX, maxi =- LLONG_MAX;
  rep(i,N) {
    cin >> x[i] >> y[i];
    mini = min(mini,min(x[i],y[i]));
    maxi = max(maxi,max(x[i],y[i]));
  }
  compute(mini,maxi);
  return 0;
}
