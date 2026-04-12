#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL)
#define REP(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define rep(i,n) REP(i,0,n-1)
#define FORD(i,b,a) for(int i=b,_a=a;i>=_a;i--)
#define ford(i,n) FORD(i,n-1,0)
#define sqr(x) ((x)*(x))
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define vll vector<ll>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define add push_back
#define len(arr) arr.size()
#define print(x) cout<<(x)<<'\n'
using namespace std;

char a[105][105];

int main() {
	SPEED;
	//freopen("in.txt", "r", stdin);
	int n, m; cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	vi v;
	rep(i, m) rep(j, n) if(a[j][i] != '.'){
		v.add(i);
		break;
	}
	rep(i, n) rep(j, m) if(a[i][j] != '.') {
		for(auto x : v) cout << a[i][x];
		print("");
		break;
	}
	return 0;
} 
