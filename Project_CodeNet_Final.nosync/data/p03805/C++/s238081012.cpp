#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
//template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//head

vi adj[9];

int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int ans = 0;
  	int n, m;
  	cin >> n >> m;
  	for(int i = 0; i < m; i++){
  		int u, v;
  		cin >> u >> v;
  		adj[u].pb(v);
  		adj[v].pb(u);
  	}
  	vi p;
  	for(int i = 1; i <=n; i++){
  		p.pb(i);
  	}
  	do{
  		bool con = true;
  		for(int i = 0; i < n - 1; i++){
  			if(count(all(adj[p[i]]), p[i+1]) == 0)
  			{
  				con = false;
  				break;
  			}
  		}
  		if(con) ans++;
  	}while(next_permutation(p.begin()+1, p.end()));
  	cout << ans << endl;
	return 0;
}
