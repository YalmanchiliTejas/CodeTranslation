#include <cassert>
#include <cstdio>
#include <vector>
#include <set>

#include <map>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <climits>

using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
	int N, M;
	cin >> N >> M;

	if (N == M) {
        cout << "Yes" << endl;
    }
		else {
        cout << "No" << endl;
    }

    return 0;
}
