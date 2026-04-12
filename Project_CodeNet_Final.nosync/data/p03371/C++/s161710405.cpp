#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define fi first
#define se second


int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int z = max(x, y);
	int ans = 10000000000;
	for(int i = 0; i <= z; i++){
		int pay = a * max(0, (x-i)) + b * max(0, (y-i)) + c * 2 * i; 
		ans = min(ans, pay);
	}
	cout << ans << endl;
	return 0;
}
