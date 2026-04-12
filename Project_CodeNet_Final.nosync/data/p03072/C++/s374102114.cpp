#include <bits/stdc++.h>

#define INF ll_MAX

typedef long long ll;

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> h(n);
	int max = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		cin >> h[i];
		if(max <= h[i]){
			max = h[i];
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}