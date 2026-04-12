#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> S(N + 2, vector<int>(26));
	vector<int> numChar(26, 100);
	for (int i = 0; i <= N; i++) {
		string s;
		getline(cin, s);
		for (auto j = 0; j < s.size(); j++) {
			S.at(i).at(s.at(j) - 'a')++;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < 26; k++) {
			numChar.at(k) = min(numChar.at(k), S.at(i).at(k));
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < numChar.at(i); j++) {
			cout << (char)(i + 'a');
		}
	}
	cout << endl;
}