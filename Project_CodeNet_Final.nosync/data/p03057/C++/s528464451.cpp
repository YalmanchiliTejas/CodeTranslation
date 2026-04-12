#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int n, m;
string s;

void allred() {
	lint v1 = 0, v2 = 0;
	lint ans = 0;
	v1 = 1;
	REP(i, n - 1) {
		lint nv1 = (v1 + v2) % MOD;
		lint nv2 = v1;
		v1 = nv1;
		v2 = nv2;
	}
	ans += (v1 + v2) % MOD;
	v1 = 0; v2 = 1;
	REP(i, n - 1) {
		lint nv1 = (v1 + v2) % MOD;
		lint nv2 = v1;
		v1 = nv1;
		v2 = nv2;
	}
	ans += v1;
	cout << (ans % MOD + MOD) % MOD << endl;
	return;
}



void solve(vector<int> suc_red, int omn) {
	int th = omn;
	if(suc_red[0] % 2 == 0) th = min(th, suc_red[0] + 1);
	lint ans = 0;
	/*
	if((n - 1) % 2 && (n - 1) <= th) {
		ans += n;
	}*/
	vector<lint> dpr(n), dpb(n);
	dpr[0] = 0;
	dpb[0] = 1;
	queue<lint> q0;
	queue<lint> q1;
	lint sum0 = 1, sum1 = 0;
	q0.push(1);
	FOR(i, 1, n) {
		if(i % 2 == 1) {
			while(!q0.empty() && (int)q0.size() > (th + 1) / 2) {
				sum0 -= q0.front(); sum0 %= MOD;
				q0.pop();
			}
			dpr[i] = sum0;
		} else {
			while(!q1.empty() && (int)q1.size() > (th + 1) / 2) {
				sum1 -= q1.front(); sum1 %= MOD;
				q1.pop();
			}
			dpr[i] = sum1;
		}
		dpb[i] = dpr[i - 1];
		if(i % 2 == 0) {
			q0.push(dpb[i]);
			sum0 += dpb[i]; sum0 %= MOD;
		} else {
			q1.push(dpb[i]);
			sum1 += dpb[i]; sum1 %= MOD;
		}
	}
	FOR(i, 1, n) {
		if(i > th) break;
		if(i % 2 == 0) continue;
		ans += dpb[n - 1 - i] * i;
		ans %= MOD;
	}
	ans += dpr[n - 1]; ans %= MOD;
	cout << (ans % MOD + MOD) % MOD << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> s;
	if(s[0] == 'B') {
		REP(i, m) {
			if(s[i] == 'B') s[i] = 'R';
			else s[i] = 'B';
		}
	}

	vector<int> suc_red;
	int c = 0;
	REP(i, m) {
		if(s[i] == 'R') c++;
		else {
			if(c != 0) suc_red.pb(c);
			c = 0;
		}
	}
	if(c != 0) suc_red.pb(c);

	if(suc_red[0] == m) {
		allred();
		return 0;
	}
 	int omn = INF;
	int roopmx = (int)suc_red.size();
	if(s[m - 1] == 'R') roopmx--;
	REP(i, roopmx) {
		if(suc_red[i] % 2) omn = min(omn, suc_red[i]);
	}
	solve(suc_red, omn);
	return 0;
}
/* --------------------------------------- */
