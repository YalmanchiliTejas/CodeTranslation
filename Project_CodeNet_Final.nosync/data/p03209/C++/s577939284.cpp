#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

ll dp[100];
ll d[100];

ll f(ll n, ll x){
	if(d[n]==x&&dp[n]!=-1)return dp[n];
	ll ret = 0;
	if(n==0){
		return 1;
	}
	if(x<=1){
		return 0;
	}
	else if(x<=1+d[n-1]){
		ret = f(n-1,x-1);
	}
	else if(x<=1+d[n-1]+1){
		ret = f(n-1,d[n-1])+1;
	}
	else if(x<=1+d[n-1]+1+d[n-1]){
		ret = f(n-1,d[n-1])+1+f(n-1,x-d[n-1]-2);
	}
	else{
		ret = f(n-1,d[n-1])+1+f(n-1,d[n-1]);
	}
	if(d[n]==x){
		dp[n] = ret;
	}
	return ret;
}

int main(){
	clr(dp,-1);
	ll ans = 0;
	ll n,x;
	cin>>n>>x;
	d[0] = 1;
	rep(i,1,100){
		d[i] = d[i-1]*2+3;
	}
	ans = f(n,x);
	cout << ans << endl;
	return 0;
}