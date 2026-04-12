#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<deque>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll m = (1e+9) + 7;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	deque<int> d;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		auto it = lower_bound(d.begin(), d.end(), a[i]);
		if (it == d.begin()) d.push_front(a[i]);
		else *(it - 1) = a[i];
	}
	cout << d.size() << endl;
	return 0;
}