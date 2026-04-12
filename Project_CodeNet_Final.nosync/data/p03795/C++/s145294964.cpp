#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	rep(i, n){
		ans += 800;
		if((i+1)%15 == 0) ans -= 200;
	}
	cout << ans << endl;
	return 0;
}