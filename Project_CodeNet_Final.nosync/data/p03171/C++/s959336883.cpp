
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
using Data = pair<ll, vector<int>>;
const ll MOD = 1e9 + 7;
const ll inf = 1LL << 50;
struct edge { ll from; ll to; ll cost; };
typedef tuple<ll, ll, ll>T;
typedef pair<ll,ll>pll;

int N;
ll A[3010];
int vis[3010][3010];
ll memo[3010][3010];
ll dp(int L,int R) {
	if (L > R)return 0;
	if (vis[L][R])return memo[L][R];
	vis[L][R] = 1;
	int diff = N - (R - L + 1);

	ll res;
	if (diff % 2 == 0) {
		res = -inf;
		res = max(res,dp(L+1,R)+A[L]);
		res = max(res,dp(L,R-1)+A[R]);
	}
	else {
		res = inf;
		res = min(res,dp(L+1,R)-A[L]);
		res = min(res,dp(L,R-1)-A[R]);
	}
	return memo[L][R] = res;
}


int main(){
	cin >> N;
	rep(i, 0, N)cin >> A[i];

	cout << dp(0, N - 1) << endl;
	
	return 0;
}

