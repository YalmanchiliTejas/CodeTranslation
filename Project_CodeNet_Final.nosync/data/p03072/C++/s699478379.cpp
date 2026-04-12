#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<bitset>
using namespace std;
#define ll long long
const ll INF = 1LL << 60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class UnionFind {
	vector<int> data;
public:
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

//input
ll N,M,L;
string S;
int main() {
	int N;
	int H[110];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	int ans = 0;
	int max = 0;
	for (int i = 0; i < N ;i++) {
		if (H[i] >= max) {
			max = H[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}