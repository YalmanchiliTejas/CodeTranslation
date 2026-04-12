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
const int MX = 10000;
ll inv[MX], f[MX], invf[MX];
void calc(){
	inv[0] = inv[1] = f[0] = f[1] = invf[0] = invf[1] = 1;
	for (int i = 2; i < MX; i++){
		inv[i] = mod - mod / i * inv[mod % i] % mod;
		f[i] = f[i - 1] * i % mod;
		invf[i] = invf[i - 1] * inv[i] % mod;
	}
}

ll dp[2][1100], C[1100][1100], grp[1100][1100];

int main(){
	calc();
	rep(i, 1100) rep(j, i+1) C[i][j] = j == 0 || j == i ? 1 : (C[i-1][j] + C[i-1][j-1]) % mod;
	rep(i, 1100) for(int j = 1; j <= i; j++) if(i % j == 0){
		grp[i][j] = f[i] * invf[j] % mod;
		rep(k, j) grp[i][j] = grp[i][j] * invf[i / j] % mod;
	}
	grp[0][0] = 1;
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	
	dp[0][n] = 1;
	int cur = 0, next = 1;
	for(int i = a; i <= b; i++){
		memset(dp[next], 0, sizeof(dp[next]));
		for(int j = 0; j <= n; j++) if(dp[cur][j]) for(int k = 0; i * k <= j; k++){
			
			if(!(k == 0 || c <= k && k <= d)) continue;
			dp[next][j - i * k] += dp[cur][j] * C[j][i * k] % mod * grp[i * k][k] % mod;
			dp[next][j - i * k] %= mod;
		}
		swap(cur, next);
	}
	cout << dp[cur][0] << endl;
	return 0;
}