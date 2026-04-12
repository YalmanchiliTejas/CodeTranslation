#include "bits/stdc++.h"
#include<random>
using namespace std;
typedef long long int lint;
typedef pair<lint, lint> plint;
typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7, INF = 1e18;

lint N, M, a, b;
bool able[8][8];
int main() {
	cin >> N >> M;
	REP(i, 8) REP(j, 8) able[i][j] = false;
	REP(i, M) {
		cin >> a >> b; a--; b--;
		able[a][b] = true;
		able[b][a] = true;
	}
	vector<lint> vec;
	REP(i, N - 1) {
		vec.push_back(i + 1);
	}
	lint cnt = 0;
	do {
		bool flag = false;
		if (!able[0][vec[0]]) flag = true;
		REP(i, N - 2) {
			flag |= (!able[vec[i]][vec[i + 1]]);
		}
		if (flag) continue;
		cnt++;
	} while (next_permutation(ALL(vec)));
	cout << cnt << endl;
}
