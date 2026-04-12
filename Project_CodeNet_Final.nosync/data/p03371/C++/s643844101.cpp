#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const int MOD = 1e9 + 7;



int main() {	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans=0;
	if (a + b > 2 * c) {
		ans += min(x, y) * 2 * c;
	}
	else {
		ans += min(x, y) * (a+b);
	}
		if (x > y) {
			if (a < 2 * c) {
				ans += (x - y)*a;
			}
			else {
				ans += (x - y) * 2 * c;
			}
		}
		else {
			if (b < 2 * c) {
				ans += (y - x)*b;
			}
			else {
				ans += (y - x) * 2 * c;
			}
		}
	cout << ans << endl;



	return 0;

}