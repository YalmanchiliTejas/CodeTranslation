#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
	int n;
	cin >> n;
	int h[n];
	rep(i,n){
		cin >> h[i];
	}
	int now = 0, ans = 0;
	rep(i,n){
		if(h[i] >= now){
			ans++;
			now = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}