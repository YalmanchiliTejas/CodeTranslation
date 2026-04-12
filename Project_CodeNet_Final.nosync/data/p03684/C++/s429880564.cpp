#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define MAP map<int,int>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e17;


void ANS(bool flag){
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Ans(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void ans(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int node[100000] = {};

int root(int n) {
	if (node[n] == n) return n;
	else return node[n] = root(node[n]);
}

void unite(int n, int m) {
	if (n > m) swap(n, m);
	n = root(n);
	m = root(m);
	if (n == m) return;
	else node[m] = n;
}


struct edge { int cost, from, to; };

bool operator<(const edge &left, const edge &right){
	return left.cost < right.cost;
}

int main() {
	int N;
	cin >> N;
	multiset<PAIR> stx;
	multiset<PAIR> sty;

	REP(i, N) {
		int x, y;
		cin >> x >> y;
		stx.insert({ x,i });
		sty.insert({ y,i });
	}

	auto itrx = stx.begin();
	PAIR x1 = *itrx;
	itrx++;
	PAIR x2 = *itrx;

	auto itry = sty.begin();
	PAIR y1 = *itry;
	itry++;
	PAIR y2 = *itry;

	multiset<edge> st;
	
	REP(i,N - 1){
		int costx = abs(x2.first - x1.first);
		st.insert({ costx,x1.second,x2.second });

		x1 = x2;
		itrx++;
		x2 = *itrx;

		int costy = abs(y2.first - y1.first);
		st.insert({ costy,y1.second,y2.second });

		y1 = y2;
		itry++;
		y2 = *itry;
	}

	REP(i, N) node[i] = i;
	ll sum = 0;
	for(auto itr = st.begin();itr != st.end();itr++){
		edge e = *itr;
		if (root(e.from) == root(e.to)) continue;
		sum += e.cost;
		unite(e.from, e.to);	
	}
	cout << sum << endl;

	return 0;
}
