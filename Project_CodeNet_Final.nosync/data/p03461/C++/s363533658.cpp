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
	int a, b; cin >> a >> b;
	vector<vi> v(a, vi(b));
	rep(i, a) rep(j, b) cin >> v[i][j];
	
	vector<vi> dist(101, vi(101));
	for(int i = 1; i <= a; i++) for(int j = 1; j <= b; j++){
		//x = i, y = jとしたとき
		//ki + lj + dist[k][l] >= v[i][j]
		rep(k, 101) rep(l, 101){
			dist[k][l] = max(dist[k][l], v[i-1][j-1] - k * i - l * j);
		}
	}
	for(int i = 1; i <= a; i++) for(int j = 1; j <= b; j++){
		int mn = inf;
		rep(k, 101) rep(l, 101){
			mn = min(mn, k * i + l * j + dist[k][l]);
		}
		if(mn != v[i-1][j-1]){
			dbg(i, j, mn, v[i-1][j-1]);
			dbg(dist[1][0]);
			cout << "Impossible" << endl;
			return 0;
		}
	}
	int m = 200 + 101 * 101;
	
	cout << "Possible" << endl;
	cout << 202 << " " << m << endl;
	rep(i, 100) cout << i+1 << " " << i+2 << " X" << endl;
	rep(i, 100) cout << i+102 << " " << i+103 << " Y" << endl;
	rep(i, 101) rep(j, 101){
		cout << i+1 << " " << 202-j << " " << dist[i][j] << endl;
	}
	cout << 1 << " " << 202 << endl;
	
	return 0;
}