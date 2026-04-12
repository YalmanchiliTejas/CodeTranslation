#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, a, b, edge[10][10], use[10], ans;

void dfs(ll s, ll cnt){
	if(cnt == n){
		ans++;
	}
	else{
		use[s] = 1;
		rep(i, 1, n){
			if(edge[s][i] == 1 && use[i] == 0){
				dfs(i, cnt+1);
			}
		}
		use[s] = 0;
	}
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	memset(edge, 0, sizeof(edge));
	rep(j, 1, m){
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	
	memset(use, 0, sizeof(use));
	ans = 0;
	dfs(1, 1);
	
	print(ans)
	return 0;
}