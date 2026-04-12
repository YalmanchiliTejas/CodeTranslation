#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pii >


// int mod=1e9+7;
inline int mul(int a,int b, int mod){return (a*1ll*b)%mod;}
inline int add(int a,int b, int mod){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b, int mod){a-=b;if(a<0)a+=mod;return a;}
inline int power(int a,int b, int mod){int rt=1;while(b>0){if(b&1)rt=mul(rt,a, mod);a=mul(a,a, mod);b>>=1;}return rt;}
inline int inv(int a, int mod){return power(a,mod-2, mod);}

int N,M;
const int MAX = 3005;

int ncr[MAX][MAX];
int dp[MAX][MAX];
int two[MAX], two1[MAX];

void pre(){
	int i,j,k;
	two[0] = two1[0] = 1;
	ncr[0][0] = 1;
	for(i=1;i<MAX;i++){
		two[i] = mul(two[i-1], 2, M);
		two1[i] = mul(two1[i-1], 2, M-1);
		for(j=0;j<MAX;j++){
			if(j==0)ncr[i][j]=1;
			else{
				// trace(i,j);
				ncr[i][j] = add(ncr[i-1][j],ncr[i-1][j-1], M);
			}
		}
	}
	dp[0][0]=1;
	for(i=1;i<MAX;i++){
		for(j=1;j<=i;j++){
			dp[i][j] = add(dp[i-1][j-1], mul(j, dp[i-1][j], M), M);
		}
	}
}

void solve(){
	int ans = 0;
	int i,j,k;
	for(i=0;i<=N;i++){
		int cur = ncr[N][i];
		cur = mul(cur, power(2, two1[N-i], M), M);
		int mt = 0;
		for(k=1;k<=i;k++){
			mt = add(mt, mul(dp[i][k], power(two[N-i], k, M), M), M );
			mt = add(mt, mul( mul(dp[i][k], k, M), power(two[N-i], k-1, M), M), M);
		}
		if(i==0)mt = 1;
		cur = mul(cur, mt, M);
		if(i&1) cur = sub(0, cur, M);

		ans = add(ans, cur, M);
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	cin>>N>>M;
	pre();
	// cout<<"ok";
	solve();
}
