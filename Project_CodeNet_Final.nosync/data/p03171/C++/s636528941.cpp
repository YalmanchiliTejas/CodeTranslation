///apigs property
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second
#define pb push_back
#define vll vector< ll >
#define vi vector< int >
#define pll pair< ll , ll >
#define pi pair< int , int >
#define all(s) s.begin() , s.end()
#define sz(s) s.size()
#define md (s + e) / 2
#define mid (l + r) / 2
using namespace std;
typedef long long ll;
ll q, dp[3005][3005][5], a[555555] , b[555555], k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
ll mem(ll x , ll y , ll op){
	//cout << op << " ";
	if(x + y == n)return 0;
	ll &r = dp[x][y][op];
	if(r != -1)return r;
	ll i = x, j = n - y - 1;
	if(!op){
		r = max(mem(x + 1 , y , op ^ 1) + a[i] , mem(x , y + 1 , op ^ 1) + a[j]);
	}
	else {
		r = min(mem(x + 1 , y , op ^ 1) , mem(x , y + 1 , op ^ 1));
	}
	return r;
}
void solve(){
	memset(dp , -1 , sizeof dp);
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
		k += a[i];
	}
	o = mem(0 , 0 , 0);
	//cout << o << endl;
	p = k - o;
	cout << o - p;
}
int main() {
    fast ;
	// cin >> q;
    q = 1;
    while(q--){
    	solve();
	}
}

