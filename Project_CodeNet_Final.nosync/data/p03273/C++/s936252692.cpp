#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<double,ll> P;

char mp[111][111];
int x[111];
int y[111];

int main(){
	
	int h,w;cin >> h >> w;
	REP(i,h){
		REP(j,w){
			cin >> mp[i][j];
			if(mp[i][j] == '#'){
				y[i]++;
				x[j]++;
			}
		}
	}
	
	REP(i,h){
		int cou = 0;
		REP(j,w){
			if(y[i] == 0 || x[j] == 0)continue;
			cout << mp[i][j];
			cou++;
		}
		if(cou)cout << endl;
	}
	return 0;
}
