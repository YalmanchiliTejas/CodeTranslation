#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<typeinfo>
#include<complex>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a;i < b; i++)
const long double PI = (acos(-1));

int main() {

	int n;
	cin >> n;

	int maxi = 0, cnt = 0;

	vector<int> h(n);
	rep(i, 0, n) {
		cin >> h[i];
		if (h[i] >= maxi) {
			cnt++;
			maxi = h[i];
		}
	}

	cout << cnt << endl;

	return 0;
}