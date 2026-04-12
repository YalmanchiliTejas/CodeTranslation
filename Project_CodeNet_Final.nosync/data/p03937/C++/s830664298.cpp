#include <bits/stdc++.h>
using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl

const lli MOD = 1000000007;
const lli LIMIT = 1000000000000000000 * 5;
const int tenfive = 100000;

int main() {
	int H, W,N = 0;
	cin >> H >> W;
	vector<string> v(H);
	for (int i = 0; i < H; i++) {
		cin >> v[i];
	}
	for (string i : v) { for (char j : i) { if (j == '#')N++; } }
	queue<pair<pair<int,int>,int>> q;
	q.push({ {0,0},1 });
	while (!q.empty()) {
		pair<pair<int, int>, int> pos = q.front(); q.pop();
		if (pos == make_pair(make_pair(H - 1, W - 1),N)) {
			cout << "Possible" << endl;
			return 0;
		}
		if (pos.first.second != W - 1)
			if (v[pos.first.first][pos.first.second + 1] == '#')
				q.push({ {pos.first.first,pos.first.second + 1},pos.second+1 });
		if (pos.first.first != H - 1)
			if (v[pos.first.first + 1][pos.first.second] == '#')
				q.push({ {pos.first.first + 1,pos.first.second},pos.second+1 });
	}
	cout << "Impossible" << endl;
	return 0;
}
