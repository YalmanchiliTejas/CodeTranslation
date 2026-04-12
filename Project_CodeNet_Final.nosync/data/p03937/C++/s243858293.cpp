#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long H, long long W, vector<string> A){
	bool flg = true;
	ll c = 0;
	rep(i, H) {
		rep(j, c) if (A[i][j] == '#') flg = false;
		for (ll j = c; j < W; j++) {
			if (A[i][j] == '.') {
				if (j == c) flg = false;
				c = j-1;
				break;
			}
			if (j == W-1) c = j;
		}
		for (ll j = c+1; j < W; j++) {
			if (A[i][j] == '#') flg = false;
		}
	}
	if (flg) cout << "Possible" << endl; else cout << "Impossible" << endl;
}

int main(){	
	long long W;
	long long H;
	scanf("%lld",&H);
	vector<string> A(H-1+1);
	scanf("%lld",&W);
	for(int i = 0 ; i <= H-1 ; i++){
		cin >> A[i];
	}
	solve(H, W, A);
	return 0;
}

