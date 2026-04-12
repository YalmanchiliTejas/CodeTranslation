#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * 1 2 3 4 5
 * 1
 * 1 2
 * 2 1 3
 * 3 1 2 4
 * 4 2 1 3 5
 * 5 3 1 2 4
 * n % 2 == 0 I need all the even indexed elements to push front 
 */
int main() {
	int n;
	cin >> n;
	deque <int> dq;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (n % 2 == 0) {
			if (i % 2 == 1)
				dq.push_back(x);
			else
				dq.push_front(x);
		}
		else {
			if (i % 2 == 0)
				dq.push_back(x);
			else
				dq.push_front(x);
		}
	}
	while(!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
}
