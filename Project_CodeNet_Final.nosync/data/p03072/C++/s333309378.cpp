#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	int ans = 0;
	int m = 0;
	for(int i = 0; i < n; ++i){
		int h;
		cin >> h;
		if(h>=m) ans++;
		m = max(h, m);
	}
	cout << ans << endl;
}