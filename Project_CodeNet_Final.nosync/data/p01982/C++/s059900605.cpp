#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	
	int n,l,r;
	while(cin >> n >> l >> r,n+l+r){
		
		vector<pair<ll,ll>> v;
		REP(i,n){
			int tmp;cin >> tmp;
			v.PB(MP(tmp,i+1));
		}
		
		
		ll ans = 0;
		
		for(int i = l;i <= r;i++){
			bool flag = false;
			
			for(int j = 0;j < n;j++){
				if(i % v[j].FI == 0){
					flag = true;
					if(v[j].SE % 2 != 0)ans++;
					break;
				}
			}
			
			if(!flag && n % 2 == 0)ans++;
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}
