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
void run() {
	int n; cin >> n;
	int x = n * 800;
	int y = 200 * (n / 15);
	cout << x - y << endl;
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
