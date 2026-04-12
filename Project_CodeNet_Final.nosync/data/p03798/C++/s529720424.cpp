#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

//#define _DEBUG_ 3

bool check(int zero, int one, int n, std::string& s) {
	std::vector<int> arr(n, 0);
	arr[0] = zero, arr[1] = one;

	for (int i = 1; i < n - 1; i++) {
		if (s[i] == 'o') {
			if (arr[i] == 1)
				arr[i + 1] = arr[i - 1];
			else
				arr[i + 1] = arr[i - 1] * (-1);
		} else {
			if (arr[i] == -1)
				arr[i + 1] = arr[i - 1];
			else
				arr[i + 1] = arr[i - 1] * (-1);
		}
	}

	if (s[0] == 'o') {
		if (arr[0] == 1 && arr[1] != arr[n - 1]) return false;
		if (arr[0] == -1 && arr[1] == arr[n - 1]) return false;
	} else {
		if (arr[0] == 1 && arr[1] == arr[n - 1]) return false;
		if (arr[0] == -1 && arr[1] != arr[n - 1]) return false;
	}

	if (s[n - 1] == 'o') {
		if (arr[n - 1] == 1 && arr[n - 2] != arr[0]) return false;
		if (arr[n - 1] == -1 && arr[n - 2] == arr[0]) return false;
	} else {
		if (arr[n - 1] == 1 && arr[n - 2] == arr[0]) return false;
		if (arr[n - 1] == -1 && arr[n - 2] != arr[0]) return false;
	}

	for (auto c : arr) {
		cout << (c == 1 ? "S" : "W");
	}
	cout << endl;
	return true;
}

void run() {
	int n;
	std::string s;
	cin >> n;
	cin >> s;
	// s s
	if (check(1, 1, n, s)) return;
	if (check(1, -1, n, s)) return;
	if (check(-1, 1, n, s)) return;
	if (check(-1, -1, n, s)) return;
	cout << "-1" << endl;
}

int main() {
#ifdef _DEBUG_
	using std::chrono::system_clock;
	using std::chrono::duration_cast;
	system_clock::time_point  start, end;
	std::ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
	for (int i = 0; i < _DEBUG_; i++) {
		cout << "-------------------------- (cnt:" << i << ")" << endl;
		start = system_clock::now();
		run();
		end = system_clock::now();
		int elapsed = duration_cast<std::chrono::milliseconds>(end - start).count();
		cout << "-------------------------- (time:" << elapsed << "ms)" << endl << endl;
}
#else
	run();
#endif
	return 0;
}
