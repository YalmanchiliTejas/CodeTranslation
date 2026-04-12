#include <bits/stdc++.h>
#define ULL unsigned long long
#define PII pair<int, int>
#define fi first
#define se second 
using namespace std;
//const LL INF = (LL) 1e9 + 5;
//const LL MOD = (LL) 1e9 + 7;
const int MAXN = 1005;

enum {AND, OR};
enum {ROW, COL};

vector<vector<int>> construct(int bit, int n, vector<int> rtp, vector<int> ctp, vector<int> rsum, vector<int> csum) {
	vector<int> reff(n, 1), ceff(n, 1);
	vector<vector<int>> res(n, vector<int>(n, -1)), nope;
	
	// Greedy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int gred0 = 0, gred1 = 0;
			gred0 |= (rtp[i] == OR && rsum[i] == 0) || (ctp[j] == OR && csum[j] == 0);
			gred0 |= (rtp[i] == AND && rsum[i] == 0 && ctp[j] == AND && csum[j] == 0);
			gred1 |= (rtp[i] == AND && rsum[i] == 1) || (ctp[j] == AND && csum[j] == 1);
			gred1 |= (rtp[i] == OR && rsum[i] == 1 && ctp[j] == OR && csum[j] == 1);
			if (gred0 && gred1) return nope;
			if (gred0) res[i][j] = 0;
			if (gred1) res[i][j] = 1;
//			if (bit == 2 && i == 0 && j == 1) {
//				cout << "WTF " << gred1 << ' ' << rtp[i] << ' ' << rsum[i] << '\n';
//			}
		}
	}
	
	// Check effect
	queue<PII> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (reff[i] && res[i][j] == rsum[i]) {
				reff[i] = 0;
				Q.push(PII(i, ROW));
			}
			if (ceff[j] && res[i][j] == csum[j]) {
				ceff[j] = 0;
				Q.push(PII(j, COL));
			}
		}
	}
	
	// Iterative update
	while (!Q.empty()) {
		PII p = Q.front();
		Q.pop();
//		if (bit == 2) cout << "QUE " << p.fi << ' ' << p.se << ' ' << res[0][1] << '\n';
		if (p.se == ROW) {
			int r = p.fi;
			for (int j = 0; j < n; j++) {
				if (ceff[j] && res[r][j] == -1) {
					res[r][j] = csum[j];
					ceff[j] = 0;
					Q.push(PII(j, COL));
				}
			}
		}
		else {
			int c = p.fi;
			for (int i = 0; i < n; i++) {
				if (reff[i] && res[i][c] == -1) {
					res[i][c] = rsum[i];
					reff[i] = 0;
					Q.push(PII(i, ROW));
				}
			}
		}
	}
	
	// Last check
	vector<int> allr, allc;
	for (int i = 0; i < n; i++) {
		if (reff[i]) allr.push_back(i);
		if (ceff[i]) allc.push_back(i);
	}
//	if (bit == 2) {
//		cout << "HERE! " << allr.size() << ' ' << allc.size() << '\n';
//		for (int i = 0; i < n; i++) {
//			cout << rsum[i] << " \n"[i == n - 1];
//		}
//		for (int i = 0; i < n; i++) {
//			cout << csum[i] << " \n"[i == n - 1];
//		}
//	}
	if (allr.empty() && allc.empty()) return res;
	if (allr.size() <= 1) return nope;
	if (allc.size() <= 1) return nope;
	
	for (int i = 0; i < allr.size(); i++) {
		for (int j = 0; j < allc.size(); j++) {
			res[allr[i]][allc[j]] = (i + j) & 1;
		}
	}
	return res;
}

ULL n, rtp[MAXN], ctp[MAXN], rsum[MAXN], csum[MAXN], ans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rtp[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> ctp[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> rsum[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> csum[i];
	}
	
	int ok = 1;
	for (int b = 0; b < 64; b++) {
		vector<int> rtp_bit(n), ctp_bit(n), rsum_bit(n), csum_bit(n);
		for (int j = 0; j < n; j++) {
			rtp_bit[j] = rtp[j];
		}
		for (int j = 0; j < n; j++) {
			ctp_bit[j] = ctp[j];
		}
		for (int j = 0; j < n; j++) {
			rsum_bit[j] = rsum[j] >> b & 1;
		}
		for (int j = 0; j < n; j++) {
			csum_bit[j] = csum[j] >> b & 1;
		}
		
		auto res = construct(b, n, rtp_bit, ctp_bit, rsum_bit, csum_bit);
		if (res.empty()) {
			ok = 0;
			break;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (res[i][j] == -1) res[i][j] = 0;
				ans[i][j] |= (ULL) res[i][j] << b;
			}
		}
	}
	
	if (ok) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << " \n"[j == n - 1];
			}
		}
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}