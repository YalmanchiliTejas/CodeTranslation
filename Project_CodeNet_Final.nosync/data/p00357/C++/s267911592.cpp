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
template<class T>struct SegTree{
	T *dat;
	int n;
	SegTree(int size = 1000000){
		for(n = 1; n < size; n *= 2);
		dat = new T[2 * n - 1];
		init();
	}
	~SegTree(){ delete [] dat; }
	
	void init(){
		rep(i, 2 * n - 1) dat[i] = 0;
	}
	void update(int k, T a){
		k += n - 1;
		dat[k] = a;
		
		while(k > 0){
			k = (k - 1) / 2;
			dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return dat[k];
		
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		
		return max(vl, vr);
	}
	T query(int a, int b){ return query(a, b, 0, 0, n); }
};
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n; cin >> n;
	vi d(n); rep(i, n) cin >> d[i];
	bool res = 1;
	auto sol = [&](){
		SegTree<int> seg(n);
		for(int i = n - 1; i >= 0; i--){
			int m = min(n - 1, i + d[i] / 10) + 1;
			seg.update(i, max(i, seg.query(i, m)));
		}
		return seg.query(0, 1) >= n - 1;
	};
	res &= sol(); reverse(all(d));
	res &= sol();
	cout << (res ? "yes" : "no") << endl;
	
	return 0;
}
