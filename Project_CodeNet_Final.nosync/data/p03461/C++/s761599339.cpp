#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }


// X: -1, Y: -2
typedef pair<int,int> pint;
int A, B;
int d[21][21];

int mid, s, t;
vector<vector<pint> > G;

int dp[550];
bool check() {
  for (int x = 1; x <= A; ++x) {
	for (int y = 1; y <= B; ++y) {
	  for (int i = 0; i < 550; ++i) dp[i] = 1<<29;
	  dp[0] = 0;
	  for (int i = 0; i < G.size(); ++i) {
		for (int j = 0; j < G[i].size(); ++j) {
		  int to = G[i][j].first;
		  int add = G[i][j].second;
		  if (add == -1) add = x;
		  else if (add == -2) add = y;

		  chmin(dp[to], dp[i] + add);
		}
	  }
	  //cout << x << ", " << y << ": " << dp[t] << endl;
	  if (dp[t] != d[x][y]) {
		return false;
	  }
	}
  }
  return true;
}
	   

int main() {
  while (cin >> A >> B) {
	memset(d, 0, sizeof(d));
	for (int i = 0; i < A; ++i) for (int j = 0; j < B; ++j) cin >> d[i+1][j+1];

	mid = 110;
	s = 0, t = mid*2;

	int V = mid*2+1;
	G.clear();
	G.resize(V);
	int E = 0;
	for (int i = 0; i < mid; ++i) {
	  G[i].push_back(pint(i+1, -1));
	  G[mid+i].push_back(pint(mid+i+1, -2));
	}

	bool ok = true;
	G[s].push_back(pint(t, d[A][B]));
	for (int i = 1; i <= A; ++i) {
	  for (int j = 1; j <= B; ++j) {
		if (!ok) break;
		int dx = -1, dy = -1, se = 1<<29;
		for (int tdx = 0; tdx <= 100; ++tdx) {
		  for (int tdy = 0; tdy <= 100; ++tdy) {
			int tse = d[i][j] - tdx * i - tdy * j;
			if (tse < 0) continue;

			bool tmp = true;
			for (int i = 1; i <= A; ++i) {
			  for (int j = 1; j <= B; ++j) {
				if (!tmp) break;
				int val = tdx * i + tdy * j + tse;
				if (val < d[i][j]) tmp = false;
			  }
			}
			if (tmp) {
			  if (chmin(se, tse)) {
				dx = tdx, dy = tdy, se = tse;
			  }
			}
		  }
		}

		if (dx == -1) {
		  ok = false;
		  break;
		}

		/*
		int p = se / 100;
		int q = se % 100;
		G.resize(G.size() + p);
		G[dx].push_back(pint(t-dy, se));
		*/
		G[dx].push_back(pint(t-dy, se));
	  }
	}



	if (!ok) {
	  puts("Impossible");
	}
	else {
	  bool res = check();
	  if (res) {
		
		puts("Possible");

		set<pair<int,pint> > S;
		for (int i = 0; i < G.size(); ++i) {
		  for (auto e : G[i]) {
			S.insert(make_pair(i, e));
		  }
		}
		
		cout << G.size() << " " << S.size() << endl;
		for (set<pair<int,pint> >::iterator it = S.begin(); it != S.end(); ++it) {
		  int from = (*it).first;
		  int to = (*it).second.first;
		  int w = (*it).second.second;
		  cout << from+1 << " " << to+1 << " ";
		  if (w == -1) cout << "X";
		  else if (w == -2) cout << "Y";
		  else cout << w;
		  cout << endl;
		}
		cout << s+1 << " " << t+1 << endl;
	  }
	  else {
		puts("Impossible");
	  }
	}
  }
}














