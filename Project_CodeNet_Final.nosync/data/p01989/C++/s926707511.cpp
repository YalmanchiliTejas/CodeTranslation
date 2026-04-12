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

string str;
int ans;

void seica_chan(int seica, int mimori){
	int now = 0;
	if(seica == 4){
		if(mimori == str.size())ans++;
		return;
	}
	bool neko = true;
	while(neko){
		now *= 10;
		now += (str[mimori] - '0');
		if(now == 0)neko = false;
		if(now < 256){
			seica_chan(seica + 1, mimori + 1);
			mimori++;
		}
		else break;
	}
}
	
int main(){
	cin >> str;
	seica_chan(0,0);
	cout << ans << endl;
	return 0;
}
