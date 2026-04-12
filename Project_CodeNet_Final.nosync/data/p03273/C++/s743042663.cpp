#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll h, w;
	cin >> h >> w;
	string  s[h];
	zep(i, 0, h){
		cin >> s[i];
	}
	
	bool bh[h], bw[w];
	memset(bh, 0, sizeof(bh));
	memset(bw, 0, sizeof(bw));
	
	zep(i, 0, h){
		zep(j, 0, w){
			if(s[i][j] == '#'){
				bh[i] = true;
				bw[j] = true;
			}
		}
	}
	
	zep(i, 0, h){
		zep(j, 0, w){
			if(bh[i] && bw[j]){
				cout << s[i][j];
			}
		}
		if(bh[i]){
			cout << endl;
		}
	}
	return 0;
}