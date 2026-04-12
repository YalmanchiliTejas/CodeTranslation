#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
long long a[100001];
vector<long long> v;

int go(int x) { // 7 6 4   6가 나왔다. 
	int l = 0;
	int r = v.size() - 1; 
	while (l <= r) {
		int mid = (l + r) / 2; 
		if (v[mid] < x) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}
int main() { // 34        
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	v.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (v[v.size() - 1] >= a[i]) {
			v.push_back(a[i]);
		}
		else {
			int j = go(a[i]);
			v[j] = a[i];
		}
	}
	cout << v.size() << '\n';


}