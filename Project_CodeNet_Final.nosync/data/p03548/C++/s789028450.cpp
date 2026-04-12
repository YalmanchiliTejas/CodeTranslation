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
	int x, y, z; cin >> x>> y>> z;
	int cnt = 0;

	for (int i = 1; y * i + z * (i + 1) <= x; i++) {
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}