#include<bits/stdc++.h>

//#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define dbg(var) {std::cout << #var << "  = " << var << nl;}
#define vi vector<int>
typedef long long ll;

using namespace std;

constexpr ll INF = numeric_limits<ll>::max();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n;
	cin >> n;
	
	vi v(istream_iterator<int>{cin} , istream_iterator<int>());
	vector<vector<vector<ll>>> dp { n + 1 , { n + 1 , { INF , INF } } }; 
	
	function<ll(int,int,bool)> rec = [&](int l , int r , bool player)
	{
		if(l == r)
			return (player ? -1LL : 1LL) * v[l];
			
		if(dp[l][r][player] != INF)
			return dp[l][r][player];
			
		ll res1 = rec(l + 1 , r , !player) + (player ? -1LL : 1LL) * v[l];
		ll res2 = rec(l , r - 1 , !player) + (player ? -1LL : 1LL) * v[r];
		
		if(player)
		{
			return dp[l][r][player] = min(res1 , res2);
		}
		else
		{
			return dp[l][r][player] = max(res1 , res2);
		}
	};

	cout << rec(0 , n - 1 , 0);

	return 0;
}