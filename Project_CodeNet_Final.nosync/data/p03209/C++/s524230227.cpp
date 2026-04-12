#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define co(x) cout << (x) << "\n"
#define ll long long
#define pb push_back
#define Never
#define To

using namespace std;

int main(){

	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	ll X;

	cin >> N >> X;

	ll ok = 0;
	ll ng = 1;
	ll pt = 1;
	for(int i = 1; i <= N; i++){
		ng = ng * 2 + 3;
		pt = pt * 2 + 1;
	}

	ll ans = 0;
	while(ng - ok > 0){

		ll mid = (ng + ok) / 2 + 1;
		pt = (pt-1)/2 + 1;

		if(mid <= X) {
			ok = mid;
			ans += pt;
			ng--;
		} else {
			ng = mid -1; // 真ん中のパティ
			ok++;
		}

	}
	cout << ans << endl;

	Never To return 0;
}
