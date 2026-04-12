#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<regex>
#include<ctype.h>
using namespace std;

int main(void) {
	
	int n, h[20];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < i; j++) {
			if (i == j) continue;
			if (h[i] < h[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ans++;
	}

	cout << ans << endl;
	return 0;

}