#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <unordered_map>
#define has(g, i) (g.find(i) != g.end())
#define ll long long
#define MAX 100000
using namespace std;
#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vvll vector<vll>
#define pq priority_queue
#define x first
#define y second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	if ((n - 1 ) % 2 == 0) {
		int prev = n - 1;
		while (prev >= 0) {
			cout << arr[prev] << " ";
			prev -= 2;
		}
		prev = 1;
		while (prev < n) {
			cout << arr[prev] << " ";
			prev += 2;
		}

		cout << endl;
		
	}
	else {
		int prev = n - 1;
		while (prev >= 0) {
			cout << arr[prev] << " ";
			prev -= 2;
		}
		prev = 0;
		while (prev < n) {
			cout << arr[prev] << " ";
			prev += 2;
		}

		cout << endl;
	}

	return 0;
}
