#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;

inline ll read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch>'9' || ch<'0'){ if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9'){ x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}

/***********************************************************/

const int maxn = 105;
int a[maxn];

int main() {
	
	int n;
	cin >> n;
	int ans = 1;
	int x;
	cin >> x;
	for (int i = 1; i < n; i++){
		int y;
		cin >> y;
		if (y >= x) {
			ans++;
			x = y;
		}
	}

	cout << ans << endl;
	
	return 0;
}