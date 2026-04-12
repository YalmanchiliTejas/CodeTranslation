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
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const ll inf = 1e18;const double INF = 1e12, EPS = 1e-9;

const int MX = 524288;
ll mx[MX], ad[MX];
ll query(int a, int b, int k, int l, int r){
	//dbg(a, b, k, l, r);
	if(b <= l || a >= r) return -inf;
	if(a <= l && r <= b) return mx[k] + ad[k];
	if(ad[k]){
		ad[k * 2 + 1] += ad[k];
		ad[k * 2 + 2] += ad[k];
		mx[k] += ad[k];
		ad[k] = 0;
	}
	ll res = max(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
	mx[k] = max(mx[k * 2 + 1] + ad[k * 2 + 1], mx[k * 2 + 2] + ad[k * 2 + 2]);
	return res;
}
void add(int a, int b, ll x, int k, int l, int r){
	//dbg(a, b, x, k, l, r);
	if(b <= l || a >= r) return;
	if(a <= l && r <= b){
		ad[k] += x;
		return;
	}
	if(ad[k]){
		ad[k * 2 + 1] += ad[k];
		ad[k * 2 + 2] += ad[k];
		mx[k] += ad[k];
		ad[k] = 0;
	}
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	mx[k] = max(mx[k * 2 + 1] + ad[k * 2 + 1], mx[k * 2 + 2] + ad[k * 2 + 2]);
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, m, N; cin >> n >> m;
	for(N = 1; N < n; N *= 2);
	
	vector<tuple<int,int,int>> v;
	rep(i, m){
		int l, r, a; cin >> l >> r >> a;
		v.emplace_back(l - 1, r, a);
	}
	sort(all(v));
	
	for(int i = m - 1, pl = n; i >= 0; i--){
		int l, r, a; tie(l, r, a) = v[i];
		ll right = max(0ll, query(pl, n, 0, 0, N));
		
		//dbg(pl, l, r, a, right);
		
		add(l, min(pl, r), a + right, 0, 0, N);
		if(pl < r) add(pl, r, a, 0, 0, N);
		pl = l;
	}
	cout << max(0ll, query(0, n, 0, 0, N)) << endl;
	return 0;
}