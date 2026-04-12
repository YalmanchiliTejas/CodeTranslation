#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;

/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/
ll const MAX = 3e3 + 5;
ll x[MAX];
ll dp[MAX][MAX] = {};
ll sumx[MAX];

int main() {
	ll n;
	cin >> n;
	sumx[0] = 0;
	REP(i, 1, n) {
		cin >> x[i];
		sumx[i] += sumx[i - 1] + x[i];
	}
	REP(i, 1, n) {
		dp[i][i] = x[i];
	}
	REP(l, 2, n) {
		REP(i, 1, n + 1 - l) {
			ll j = i + l - 1;
			dp[i][j] = max(x[i] + sumx[j] - sumx[i] - dp[i + 1][j], 
				x[j] + sumx[j - 1] - sumx[i - 1] - dp[i][j - 1]);
		}
	}
	cout << dp[1][n] - (sumx[n]  - dp[1][n]) << endl;
}