#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

int g[20][20]={0};

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u][v] = 1;
		g[v][u] = 1;
	}

	vector<int> a;
	for(int i=1;i<=n;i++){
		a.pb(i);
	}

	int ans = 0;
	do{
		bool fg = 0;
		for(int i=1;i<n;i++){
			if(!g[a[i]][a[i-1]]){
				// cout<<a[i]<<" "<<a[i-1]<<endl;
				fg = 1;
				break;
			}
		}
		if(!fg){
			ans += 1;
		}

	}while(next_permutation(a.begin()+1, a.end()));
	cout<<ans<<endl;
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
