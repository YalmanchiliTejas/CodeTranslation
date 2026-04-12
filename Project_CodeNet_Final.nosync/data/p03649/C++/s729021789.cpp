#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	
	auto calc = [&](ll x){
		ll sum = 0;
		rep(i, n){
			//ai - k*n + x - k <= n - 1
			ll k = (a[i] + x + 1) / (n + 1);
			sum += k;
		}
		return sum;
	};
	
	ll lo = -1, hi = accumulate(all(a), n - 1ll) / n, mid;
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(calc(n * mid) <= n * mid) hi = mid;
		else lo = mid;
	}
	/*
	ll ans = n * lo;
	while(calc(ans) != ans) ans++;
	while(ans >= n && calc(ans - n) == ans - n) ans -= n;
	
	for(ll i = ans - 10; i <= ans + 10; i++) dbg(i, calc(i));
	cout << ans << endl;
	*/
	for(ll a = max(0ll, n * lo - 1000); a <= n * lo + 1000; a++){
		if(calc(a) == a){
			cout << a << endl;
			return 0;
		}
	}
	assert(0);
	
	return 0;
}