#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include <set>
#include <cassert>
#include<cmath>
#include<climits>
using namespace std;
#define MOD 1000000007
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


int find(vector<long long> &arr, long long obj) {
	if (arr[arr.size() - 1] < obj)return arr.size()-1;
	if (arr[0] > obj)return -1;

	int min = 0; int max = arr.size() - 1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[min+(max-min) / 2] > obj) {
			max = min + (max - min) / 2;
		}
		else {
			min = min + (max - min) / 2;
		}
		if (max - min == 1) {
			return min;
		}
	}


}


int main() {
	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}
