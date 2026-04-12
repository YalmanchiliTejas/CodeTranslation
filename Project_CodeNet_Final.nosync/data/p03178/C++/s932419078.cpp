#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define ll long long
template<typename T, typename U> 
static inline void amin(T &x, U y){
	if(x>y)
		x = y;
}
template<typename T, typename U> 
static inline void amax(T &x, U y){
	if(x<y)
		x = y;
}
#define rep(i,n) for(int i = 0; i < n; ++i)
#define irep(i,k,n) for(int i = k; i <= n; ++i)
#define irepr(i,k,n) for(int i = k; i >= n; --i)

int inf = 2e9;
ll INF = 2e18;
const ll mod = 1e9+7;
string k;
int D, len;
ll dp[10005][105][2];

ll solve(int idx, int rem, int isSmaller){
	if(idx==len){
		return rem==0;
	}
	ll & ret = dp[idx][rem][isSmaller];
	if(ret!=-1){
		return ret;
	}
	int limit;
	if(isSmaller){
		limit = 9;
	}else{
		limit = k[idx]-'0';
	}
	ret = 0;
	for(int i=0;i<=limit;++i){
		int ns;
		if(i<k[idx]-'0'){
			ns = 1;
		}else{
			ns = isSmaller;
		}
		ret += solve(idx+1,(rem+i)%D,ns);
		ret %= mod;
	}
	return ret;
}

int main(){
	rep(x,10001){
		rep(y,102){
			dp[x][y][0] = dp[x][y][1] = -1;
		}
	}
	cin >> k;
	cin >> D;
	len = k.length();
	ll ans = solve(0, 0, 0);
	cout<<(ans-1+mod)%mod<<endl;
	return 0;
}