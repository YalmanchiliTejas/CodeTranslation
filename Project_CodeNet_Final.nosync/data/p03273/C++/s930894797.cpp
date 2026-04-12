#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vint = vector<int>;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	bool hw[h], ww[w];
	char a[h][w];
	REP(i, h){
		hw[i] = true;
		REP(j, w){
			cin >> a[i][j];
			if (a[i][j] == '#'){
				hw[i] = false;
			}
		}
	}
	REP(i, w){
		ww[i] = true;
		REP(j, h){
			if (a[j][i] == '#'){
				ww[i] = false;
			}
		}
	}
	REP(i, h){
		if (hw[i]){
			continue;
		}
		REP(j, w){
			if (ww[j]){
				continue;
			}
			cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}