#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;

int a[200][200];
signed main(){
	int h, w;
	scanf("%lld%lld", &h, &w);
	rep(i,h){
		string str;
		cin >> str;
		rep(j,w){
			if(str[j] == '#')a[i][j] = 2;
			else a[i][j] = 1;
		}
	}
	
	rep(i,h){
		int f = 1;
		rep(j,w){
			if(a[i][j] == 2)f = 0;
		}
		if(f)rep(j,w){
			a[i][j] = 0;
		}
	}
	rep(j,w){
		int f = 1;
		rep(i,h){
			if(a[i][j] == 2)f = 0;
		}
		if(f)rep(i,h){
			a[i][j] = 0;
		}
	}
	
	rep(i,h){
		int f = 0;
		rep(j,w){
			if(a[i][j] == 1)printf(".");
			else if(a[i][j] == 2)printf("#");
			if(a[i][j])f = 1;
		}
		if(f)printf("\n");
	}
	return 0;
}




