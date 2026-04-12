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

vector<vector<int> > vCon;
int suc_cnt = 0;

void nextnode(set<int>& visited, int now, int num, int final) {
	int cnt = 0;
	if (visited.size() == final) {
		suc_cnt++;
	}
	else {
		for (int i = 0; i != vCon[now].size(); ++i) {
			const int next = vCon[now][i];
			if (visited.find(next) != visited.end()) {
				continue;
			}

			else {
				set<int> newvisited = visited;
				newvisited.insert(next);
				nextnode(newvisited, next, num + 1, final);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//2013
	int N, M;
	cin >> N >> M;

	vector<int> vA(M);
	vector<int> vB(M);
	rep(i, M) cin >> vA[i] >> vB[i];
	rep(i, M) {vA[i]--; vB[i]--;}

	vCon.resize(N);

	for (int i = 0; i != M; ++i) {
		vCon[vA[i]].push_back(vB[i]);
		vCon[vB[i]].push_back(vA[i]);
	}

	set<int> visited;
	visited.insert(0);
	nextnode(visited, 0, 0, N);


	cout << suc_cnt << endl;

	return 0;
}