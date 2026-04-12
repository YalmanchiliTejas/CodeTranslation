#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define t(x) cerr<<#x<<":"<<x<<'\n';
#define t2(a,n) { cerr<<#a<<" = "; for(int i=0; i<n; ++i){ cerr << a[i] << ' '; } ; cerr <<'\n'; }
#define t3(a){ cerr<<#a<<" = "; for(auto i: a){ cerr<<i<<" "; } cerr<<'\n'; }
const int N = 1e5+5;
vector<pair<pair<int,int>,ll>> data;
typedef pair<ll,int> pi;
vector<pi> adj[N];
int no,m;

void Prims(){
  for(int i=0; i<data.size(); ++i){
    int a,b; ll w;
    a = data[i].first.first;
		b = data[i].first.second;
		w = data[i].second;
    a--; b--;
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
  }
  ll ans = 0;
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  set<int> done;
  for( auto i : adj[0] ){
    pq.push(i);
  }
  done.insert(0);
  while(!pq.empty()){
    auto x = pq.top(); pq.pop();
    if( done.find(x.second) == done.end() ){
      ans += x.first;
      for(auto j : adj[x.second] ){
        pq.push(j);
      }
      done.insert(x.second);
    }
  }
  cout<<ans<<'\n';
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<pair<pair<ll,ll>,int>> pts,pt2;
	for(int i=0; i<n; ++i){
		ll x,y;cin>>x>>y;
		pts.push_back({{x,y},i+1});
		pt2.push_back({{y,x},i+1});
	}
	sort(pts.begin(),pts.end());
	sort(pt2.begin(),pt2.end());
	ll ans = 0;
	ll ans2=0;
	for(int i=1; i<n; ++i){
		int a1 = pts[i].second;
		int a2 = pts[i-1].second;
		data.push_back({ {a1,a2}, (ll)abs(pts[i].first.first- pts[i-1].first.first) });
		a1 = pt2[i].second;
		a2 = pt2[i-1].second;
		data.push_back({ {a1,a2}, (ll)abs(pt2[i].first.first- pt2[i-1].first.first) });
	}
	Prims();



	#ifdef LOL
	    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
	return 0;
}
