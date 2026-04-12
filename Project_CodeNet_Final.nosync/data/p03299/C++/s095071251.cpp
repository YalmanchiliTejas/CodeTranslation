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

const int mod = 1e9 + 7;
map<vi, int> dp, dp2;

int pw2(int x){
	int res = 1;
	for(ll m = 2; x; x /= 2){
		if(x & 1) res = res * m % mod;
		m = m * m % mod;
	}
	return res;
}
vector<vi> children(const vi &h){
	int mn = *min_element(all(h)), n = h.size();
	vector<vi> cs;
	vi tmp;
	rep(i, n){
		if(h[i] > mn) tmp.pb(h[i] - mn);
		if(h[i] == mn || i == n-1){
			if(tmp.size()) cs.pb(tmp);
			tmp.clear();
		}
	}
	return cs;
}
int rec2(const vi &h){
	if(dp2.count(h)) return dp2[h];
	int &res2 = dp2[h], mn = *min_element(all(h));
	res2 = pw2(mn);
	for(vi &c : children(h)) res2 = (ll)res2 * rec2(c) % mod;
	return res2;
}
int rec(const vi &h){
	if(dp.count(h)) return dp[h];
	int &res = dp[h];
	int mn = *min_element(all(h)), rem = count(all(h), mn);
	
	//パターン1 i列目とi+1列目が反転でも同じでもいい
	//パターン2 i列目とi+1列目が反転
	int res1 = pw2(rem);
	int res2 = (pw2(mn) + mod - 2) % mod;
	for(vi &c : children(h)){
		res1 = res1 * (ll)(rec(c) + rec2(c)) % mod;
		res2 = res2 * (ll)rec2(c) % mod;
	}
	return res = (res1 + res2) % mod;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n; cin >> n;
	vi h(n); rep(i, n) cin >> h[i];
	cout << rec(h) << endl;
	
	return 0;
}