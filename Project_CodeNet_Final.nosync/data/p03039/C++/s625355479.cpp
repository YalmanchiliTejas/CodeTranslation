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
const int MX = 210000;
ll inv[MX], f[MX], invf[MX];
void calc(){
	inv[0] = inv[1] = f[0] = f[1] = invf[0] = invf[1] = 1;
	for (int i = 2; i < MX; i++){
		inv[i] = mod - mod / i * inv[mod % i] % mod;
		f[i] = f[i - 1] * i % mod;
		invf[i] = invf[i - 1] * inv[i] % mod;
	}
}
inline ll C(ll n, ll k){
	return f[n] * invf[k] % mod * invf[n - k] % mod;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	calc();
	
	int n, m, k; cin >> n >> m >> k;
	if(n > m) swap(n, m);
	
	ll co = C(n * m - 2, k - 2);
	ll ans = 0, sum = 0;
	for(int i = 1; i < m; i++) sum += (ll)i * (m - i); sum %= mod;
	ans = sum * n % mod;
	
	rep(i, n){
		ans += 2 * sum * i;
		ans += i * (i + 1ll) / 2 * m % mod * m % mod;
	}
	
	ans = ans % mod * co % mod;
	
	cout << ans << endl;
	
	return 0;
}