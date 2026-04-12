#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:
const ll mod=1000000007LL;

#define error(args...) { vector<string> _debug = split(#args, ',');err(begin(_debug), args);}

vector<string> split(const string& s, char c){
	vector<string> v;stringstream ss(s);string x;
	while (getline(ss, x, c)) v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {cerr << endl;}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a,Args... args){
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << " ",err(++it, args...);
}

const int limit=1000;
ll C[1010][1010];

void init(){
	rep(i,limit+1){
		rep(j,i+1){
			if(j==0 or j==i)
				C[i][j]=1LL;
			else
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}

ll dp[1010][1010];
ll num[1010][1010];

ll inv[1010];
ll fact[1010];


int main(void){
	init();

	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;

	inv[1]=1LL;
	rep(i,2,limit+1) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	
	fact[0]=1LL;
	rep(i,1,limit+1) fact[i]=1LL*i*fact[i-1]%mod;

	
	num[0][0]=1LL;
	rep(i,1,limit+1)rep(j,1,i+1){
		if(i%j!=0) continue;
		int unit=i/j;
		num[i][j]=1LL*C[i][unit]*num[i-unit][j-1]%mod*inv[j]%mod;
	}

	dp[a][n]=1LL;
	rep(i,a,b+1){
		rep(k,n+1){
			dp[i+1][k]+=dp[i][k];
			dp[i+1][k]%=mod;
		}

		rep(j,c,d+1){
			rep(k,i*j,n+1){	
				ll add=1LL*dp[i][k]%mod*C[k][i*j]%mod*num[i*j][j]%mod;
				dp[i+1][k-i*j]+=add;
				dp[i+1][k-i*j]%=mod;
			}
		}
	}

	//rep(i,a,b+2)rep(j,n+1) error(i,j,dp[i][j]);
	// 280
	cout << dp[b+1][0] << endl;
	return 0;
}