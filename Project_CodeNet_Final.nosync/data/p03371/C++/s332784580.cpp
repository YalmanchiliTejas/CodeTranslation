#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;



int main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans=0;
	int mxy = (x >= y) ? x : y, mixy = x + y - mxy;
	
	if (mixy == x && (a*mixy + b * mixy < 2 * c*mixy)) {
		ans += (a + b)*mixy+b*(mxy-mixy);
	}
	else if (mixy == y && (a*mixy + b * mixy < 2 * c*mixy)) {
		ans += (a + b)*mixy + a * (mxy- mixy);
	}
	else {
		ans += 2 * c*mixy;
		if(mixy == x&& 2*c > b){
			ans += (mxy - mixy)*b;
		}
		else if (mixy == y && 2 * c > a) {
			ans += (mxy - mixy)*a;
		}
		else {
			ans += 2 * c*(mxy - mixy);
		}
	}

	cout << ans << endl;

	return 0;
}