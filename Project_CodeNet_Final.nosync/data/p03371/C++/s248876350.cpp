#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = 1001001001;
	int double_c = c * 2;
	for(int i = 0; i <= 100000; i++){
		int temp;
		temp = i * double_c + a * max(0, x - i) + b * max(0, y - i);
		ans = min(ans, temp);	
	}

	cout << ans << endl;
}