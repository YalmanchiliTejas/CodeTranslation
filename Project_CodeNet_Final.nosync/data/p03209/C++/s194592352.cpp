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

long long berger[51];

long long niku[51];
long long count(int n) {
	if (berger[n] != 0)return berger[n];
	
	return berger[n] = count(n - 1) * 2 + 3;
}
long long countniku(int n) {
	if (niku[n] != 0)return niku[n];
	return niku[n] = countniku(n - 1) * 2 + 1;
}



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
	long long n, x;
	cin >> n >> x;
	berger[0] = 1;
	niku[0] = 1;
	long long total = 0;
	for (int i = n; i > 0; i--) {
		if (x >= count(i - 1) + 2) {
			x -= count(i - 1) + 2;
			total += countniku(i- 1) + 1;
		}
		else {
			x -= 1;
		}
	}

	if (x > 0)total++;
	cout << total;
	
	return 0;
}