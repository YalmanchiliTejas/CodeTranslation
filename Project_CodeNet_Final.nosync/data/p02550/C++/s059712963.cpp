#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, gs, shu;
int x, m;
int vis[100050];
int t[100050];
ll sm[100050], tot;
int main() {
	cin >> n >> x >> m;
	int i;
	ll ji = x;
	int mod = m, duo;
	vis[ji] = 1;
	++tot;
	sm[tot] = (sm[tot - 1] + ji);//cerr << tot << " " << sm[tot] - sm[tot - 1] << endl;
	for(i = 2; i <= n; ++i) {
		ji = ji * ji % m;
		if(vis[ji]) break;
		++tot;vis[ji] = tot;
		sm[tot] = (sm[tot - 1] + ji);
		//cerr << tot << " " << sm[tot] - sm[tot - 1] << endl;
	}
	ll ans, zq;
	ji = vis[ji];//cerr << ji << endl;
	ans = sm[ji - 1];//cerr << ans << endl;
	shu = n - (ji - 1);//cerr << shu << endl;
	zq = tot - ji + 1;//cerr << zq << endl;
	gs = shu / zq;//cerr << gs << endl;
	ll yu = shu % zq; //cerr << shu << endl;
//	cerr << sm[tot] - sm[ji - 1] << endl;
	
	ans = ans + gs * (sm[tot] - sm[ji - 1]) + sm[yu + ji - 1] - sm[ji - 1];
	cout << ans;
	return 0;
}