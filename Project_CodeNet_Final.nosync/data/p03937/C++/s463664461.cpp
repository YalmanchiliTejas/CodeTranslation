

#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


int main() {
	int h, w, i, j;
	cin >> h >> w;
	vector<vector<char> > a(h + 2, vector<char>(w + 2));
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}

	int nowi = 1, nowj = 1;
	while (nowi != h || nowj != w) {
		if (nowi == 1 && nowj == 1) {
			if (a[nowi + 1][nowj] == a[nowi][nowj + 1]) {
				cout << "Impossible" << endl;
				return 0;
			}
			else if (a[nowi + 1][nowj] == '#') {
				nowi = nowi + 1;
			}
			else {
				nowj = nowj + 1;
			}
		}
		else {
			if ((a[nowi + 1][nowj] == a[nowi][nowj + 1]) || (a[nowi - 1][nowj] == a[nowi][nowj - 1])) {
				cout << "Impossible" << endl;
				return 0;
			}
			else if (a[nowi + 1][nowj] == '#') {
				nowi = nowi + 1;
			}
			else {
				nowj = nowj + 1;
			}
		}
	}
	int cnt = 0;
	for (i = 0; i < 4; i++) {
		if (a[h + dx[i]][w + dy[i]] == '#') {
			cnt++;
		}
	}
	if (cnt == 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}