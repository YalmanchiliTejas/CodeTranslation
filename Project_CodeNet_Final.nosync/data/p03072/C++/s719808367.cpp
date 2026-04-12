#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<tuple>
#include<utility>
#include<stack>
using namespace std;

using ll=long long int;

int main() {
	
	int n;
	cin >> n;

	int h[101] = {};
	for (int i = 0; i < n; i++)cin >> h[i];

	int cnt = 1;

	int maxi = h[0];

	for (int i = 1; i < n; i++) {
		if (h[i] >= maxi) {
			cnt++;
			maxi = h[i];
		}
	}
	
	cout << cnt << endl;

	return 0;
}


