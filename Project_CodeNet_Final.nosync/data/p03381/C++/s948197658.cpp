#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define ABS(a,b) max(a,b) - min(a,b)

int n,a,out[210000];
vector<pair<int,int>> s;

int main() {
	cin >> n;
	REP(i, n) {
		cin >> a;
		s.push_back(make_pair(a, i + 1));
	}
	sort(ALL(s));
	REP(i, n) {
		if (i + 1 <= n / 2) out[s[i].second - 1] = s[n / 2].first;
		else out[s[i].second - 1] = s[n / 2 - 1].first;
	}
	REP(i, n) cout << out[i] << endl;
}
	
