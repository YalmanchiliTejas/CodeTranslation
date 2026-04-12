#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

vector<vector<int>> con;

int dfs(int n,set<int> &st){
	if(sz(st)==0) return 1;
	int ans=0;
	for(auto &i:con[n]){
		if(st.count(i)){
			st.erase(i);
			ans+=dfs(i,st);
			st.insert(i);
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,e; cin>>n>>e;
	con.resize(n);
	int s,t;
	For(i,0,e-1){
		cin>>s>>t;
		s--; t--;
		con[s].emplace_back(t);
		con[t].emplace_back(s);
	}
	set<int> st;
	For(i,1,n-1) st.insert(i);
	cout<<dfs(0,st)<<"\n";
	return 0;
}



























