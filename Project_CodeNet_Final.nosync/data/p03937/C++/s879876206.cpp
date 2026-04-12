#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;
typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W;
	cin >> H >> W;
	int cnt = 0;
	rep(i,H){
		rep(j,W){
			char a;
			cin >> a;
			if(a == '#') cnt++;
		}
	}

	if(cnt == H + W - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;

	return 0;
}