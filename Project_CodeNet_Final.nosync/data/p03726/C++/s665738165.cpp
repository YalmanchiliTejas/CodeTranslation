

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

#define N 100010
vii G(N, vi());

int dfs(int parent, int now) {
	if (parent != -1 && G[now].size() == 1) {
		return 1;
	}
	int res = 0;
	for (int i = 0; i < G[now].size(); i++) {
		if (G[now][i] == parent) {
			continue;
		}
		res += dfs(now, G[now][i]);
	}
	if (res >= 2) {
		cout << "First" << endl;
		exit(0);
	}
	else if (res == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int n, i, j;
	cin >> n;
	vi a(n - 1), b(n - 1);
	for (i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	int res = dfs(-1, 0);
	if (res == 1) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
}