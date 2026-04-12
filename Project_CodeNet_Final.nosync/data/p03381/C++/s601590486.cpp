#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main()
{
	int n;cin >> n;
	vector<pair<int,int>> v;
	vector<int> ans(n);
	REP(i,n){
		int tmp;
		cin >> tmp;
		v.PB(MP(tmp,i));
	}
	
	sort(ALL(v));
	
	
	REP(i,n){
		if(i < (n/2)){
			ans[v[i].SE] = v[n/2].FI;
		}else
		{
			ans[v[i].SE] = v[n/2 - 1].FI;
		}
	}
	
	REP(i,n){
		cout << ans[i] << endl;
	}
	
	return 0;
}