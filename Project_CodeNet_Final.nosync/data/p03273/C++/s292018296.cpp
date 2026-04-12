#include <bits/stdc++.h>

using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl
#define HYPP(x) hypot(x.first,x.second)

const lli MOD = 1000000007;
const lli LIMIT = 1000000000000000000 * 5;
const int tenfive = 100000;



int main() {
	int H, W;
	cin >> H >> W;
	vector<string> grid(H);
	for (int i = 0; i < H; i++) {
		cin >> grid[i];
	}
	//横
	set<int> yN;
	for (int y = 0; y < H; y++) {
		bool allEmpty = true;
		for (int x = 0; x < W; x++) {
			if (grid[y][x] == '#')allEmpty = false;
		}
		if (allEmpty)yN.insert(y);
	}
	//縦
	set<int> xN;
	for (int x = 0; x < W; x++) {
		bool allEmpty = true;
		for (int y = 0; y < H; y++) {
			if (grid[y][x] == '#')allEmpty = false;
		}
		if (allEmpty)xN.insert(x);
	}

	for (int y = 0; y < H; y++) {
		if (yN.count(y))continue;
		for (int x = 0; x < W; x++) {
			if (xN.count(x))continue;
			cout << grid[y][x];
		}
		cout << endl;
	}
	return 0;
}
