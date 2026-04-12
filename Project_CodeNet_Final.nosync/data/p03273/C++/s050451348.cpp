#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
#include "stdio.h"
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const long long mod_const = 1e9+7;
using MIte = multimap<long, long, greater<long> >::iterator;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// long long?
	long long H, W;
	cin >> H >> W;

	vector<vector<char> > vvA;
	rep(i, H) {
		vector<char> vtmp(W);
		bool black = false;
		rep(j, W) {
			cin >> vtmp[j];
			if (vtmp[j] == '#') black = true;
		}
		if (black) {
			vvA.push_back(vtmp);
		}
	}


	vector<vector<char> > vvA2(W);
	for (int i = 0; i != W; ++i) {
		vector<char> vtmp(vvA.size());
		for (int j = 0; j != vvA.size(); ++j) {
			vtmp[j] = vvA[j][i];
		}
		vvA2[i] = vtmp;
	}

	vector<vector<char> > vvA3;
	for (int i = 0; i != W; ++i) {
		bool black = false;
		for (int j = 0; j != vvA.size(); ++j) {
			if (vvA2[i][j] == '#') black = true;
		}
		if (black) {
			vvA3.push_back(vvA2[i]);
		}
	}

	vector<vector<char> > vvA4(vvA.size());
	for (int i = 0; i != vvA.size(); ++i) {
		vector<char> vtmp(vvA3.size());
		for (int j = 0; j != vvA3.size(); ++j) {
			vtmp[j] = vvA3[j][i];
		}
		vvA4[i] = vtmp;
	}

	rep(i, vvA4.size()) {
		rep(j, vvA3.size()) {
			cout << vvA4[i][j];
		}
		cout << endl;
	}
	
	return 0;

}