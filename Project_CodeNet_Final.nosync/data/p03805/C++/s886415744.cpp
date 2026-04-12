#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<set<int>> G(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].insert(b);
		G[b].insert(a);
	}
	int ans = 0;
	vector<int> v(n);
	rep(i,n) v[i] = i;
	do{
		if(v[0] != 0) continue;
		bool yes = true;
		rep(i,n-1){
			if(G[v[i]].find(v[i+1]) == G[v[i]].end()) yes = false;
		}
		if(yes) ans++;
	} while(next_permutation(v.begin(), v.end()));
	cout << ans << endl;
    return 0;
}