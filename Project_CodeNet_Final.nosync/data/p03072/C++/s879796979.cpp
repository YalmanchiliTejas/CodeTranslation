#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>




#define rep(p,q) for(int i = p;i < q;i++)
#define ll long long

using namespace std;

const int cons = 1e9 + 7;

//B

int main(void) {
	int n;
	cin >> n;
	vector<int> h = vector<int>(n);
	rep(0, n) {
		cin >> h[i];
	}
	int max = 0;
	int ans = 0;
	rep(0, n) {
		if (h[i] >= max) {
			ans++;
			max = h[i];
		}
	}
	cout << ans << endl;
}