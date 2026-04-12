#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const ll M = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){
		ret *= x;
		ret %= M;
	}
	return ret;
}

int main(){
	ll n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	
	ll fact[1002];
	ll inv[1002];
	ll C[1002];
	ll D[1002];
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1 ; i < 1002 ; i ++){
		fact[i] = fact[i-1]*i;
		fact[i] %= M;
		inv[i] = modpow(fact[i],M-2);
		C[i] = modpow(inv[i],c);
	}
	
	ll dp[2][1002] = {};
	dp[0][0] = fact[n];
	for(int i = a ; i <= b ; i ++){
		for(int j = 0 ; j <= n ; j ++){
			dp[1][j] = 0;
			ll x[1002];
			for(int k = c ; k <= d ; k ++){
				if(i*k > j)break;
				x[k] = modpow(inv[i],k)*inv[k];
				x[k] %= M;
			}
			for(int k = c ; k <= d ; k ++){
				if(i*k > j)break;
				dp[1][j] += dp[0][j-k*i]*x[k];
				dp[1][j] %= M;
			}
		}
		/*	if(j < i*c)dp[1][j] = 0;
			else {
				dp[1][j] = dp[1][j-i]*inv[i]+dp[0][j-c*i]*C[i];
				if(j >= i*(d+1))dp[1][j] += M-(dp[0][j-(d+1)*i]*modpow(inv[i],d+1))%M;
				dp[1][j] %= M;
			}
		}*/
		for(int j = 0 ; j <= n ; j ++){
			dp[0][j] += dp[1][j];
			dp[0][j] %= M;
		}
	}
	cout << dp[0][n] << endl;
}

