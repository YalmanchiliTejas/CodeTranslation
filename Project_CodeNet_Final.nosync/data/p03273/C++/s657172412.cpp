#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007

 

int main() {
	vector<string> a;
	int H, W; cin >> H >> W;
	bool mask[110] = { false };
	for (int i = 0; i < H; i++) {
		string ipts;
		string comp(W, '.');
		cin >> ipts;
		if (ipts == comp)continue;
		a.push_back(ipts);
		for (int j = 0; j < W; j++) {
			if (ipts[j] == '#')mask[j] = true;
		}
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < W; j++) {
			if (mask[j] == true)cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}