#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007


int main()
{
	int n;
	cin >> n;
	int a[100001];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	if(n % 2 == 0){
		long long int ans = 0;
		for(int i = 0; i < n / 2 - 1; i++){
			ans += 2 * a[i];
		}
		ans += a[n / 2 - 1];
		ans -= a[n / 2];
		for(int i = n / 2 + 1; i < n; i++){
			ans -= 2 * a[i];
		}
		cout << ans << endl;
	} else {
		long long int res1 = 0;
		long long int res2 = 0;
		for(int i = 0; i < n / 2 - 1; i++){
			res1 += 2 * a[i];
			res2 += 2 * a[i];
		}
		res1 += 2 * a[n / 2 - 1];
		res1 -= a[n / 2];
		res1 -= a[n / 2 + 1];
		res2 += a[n / 2 - 1];
		res2 += a[n / 2];
		res2 -= 2 * a[n / 2 + 1];
		for(int i = n / 2 + 2; i < n; i++){
			res1 -= 2 * a[i];
			res2 -= 2 * a[i];
		}
		cout << max(res1, res2) << endl;
	}
}

