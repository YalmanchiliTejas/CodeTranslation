#include<iostream>
#include<map>
#include<algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <list>


constexpr int INF = 1050000000;
constexpr int MOD = 1000000007;
constexpr long long LONGINF = 1005000000000000000;
using namespace std;

using ll = long long;

class UnionFind {
private:
	std::vector<int> parent;
	std::vector<int> height;
	std::vector<int> m_size;

public:
	UnionFind(int size_) : parent(size_), height(size_, 0), m_size(size_, 1) {
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	void init(int size_) {
		parent.resize(size_);
		height.resize(size_, 0);
		m_size.resize(size_, 1);
		for (int i = 0; i < size_; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		int t = size(x) + size(y);
		m_size[x] = m_size[y] = t;
		if (height[x] < height[y]) parent[x] = y;
		else parent[y] = x;
		if (height[x] == height[y]) ++height[x];
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		if (parent[x] == x) return m_size[x];
		return size(parent[x] = find(parent[x]));
	}
};


int main() {

	string left = "qwertasdfgzxcvb";
	string right = "yuiophjklnm";
	
	while (1) {
		string s; cin >> s;
		if (s == "#") { return 0; }

		bool x;//true:right false:left

		if (left.find(s[0]) != -1) {
			x = false;
		}
		else {
			x = true;
		}

		int ans = 0;

		for (int i = 1; i < s.size(); i++) {
			if (x) {
				if (right.find(s[i]) != -1) {}
				else {
					x = false;
					ans++;
				}
			}
			else {
				if (left.find(s[i]) != -1) {}
				else {
					x = true;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

}
