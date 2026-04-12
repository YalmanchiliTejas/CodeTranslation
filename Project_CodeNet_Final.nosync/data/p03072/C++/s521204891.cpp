#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n, maxi = 0, ans = 0;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++){
		cin >> h[i];
	}
	for (int i = 0; i < n; i++){
		if (maxi <= h[i]) ans++;
		maxi = max(maxi, h[i]);
	}
	cout << ans << endl;
 	return 0;
}

