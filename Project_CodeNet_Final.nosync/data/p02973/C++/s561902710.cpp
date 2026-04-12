#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a;

int main() {
	int n, x; scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		auto it = upper_bound(a.begin(), a.end(), x, greater<int>());
		if (it == a.end()) a.push_back(x);
		else *it = x;
	}
	cout << a.size();
}