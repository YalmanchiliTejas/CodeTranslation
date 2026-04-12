#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int val[70][100010];
int nxt[70][100010];

signed main(){
	int n, x, m;
	cin >> n >> x >> m;


	for(int i = 0;i < m;i++){
		val[0][i] = i;
		nxt[0][i] = (i*i) % m;
	}


	for(int b = 1;b <= 60;b++){
		for(int i = 0;i < m;i++){
			val[b][i] = val[b-1][i] + val[b-1][nxt[b-1][i]];
			nxt[b][i] = nxt[b-1][nxt[b-1][i]];
		}
	}

	int ans = 0;
	int idx = x;
	for(int b = 0;b <= 60;b++){
		if(n & (1ll << b)){
			ans += val[b][idx];
			idx = nxt[b][idx];
		}
	}
	cout << ans << endl;
	return 0;
}
