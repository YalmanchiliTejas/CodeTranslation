#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdio.h>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>

using namespace std;

#define Int int64_t

void printVec(std::vector<int>& vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void printVec1(std::vector<string>& vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
	vector.erase(vector.begin() + index);
}




int main() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int maxx = h[0];
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (h[i] >= maxx) {
			count++;
			maxx = h[i];
		}
	}

	cout << count << endl;

	return 0;
}