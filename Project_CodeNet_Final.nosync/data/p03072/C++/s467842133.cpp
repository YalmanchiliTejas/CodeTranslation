#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N;

	cin >> N;
	int h[22];

	int nowmax = 0;

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		cin >> h[i];
		if (nowmax <= h[i]) {
			nowmax = h[i]; 
			ans++;
		}
	}

	cout << ans;
}