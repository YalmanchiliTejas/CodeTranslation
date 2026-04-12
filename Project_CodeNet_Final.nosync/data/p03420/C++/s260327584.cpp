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

using namespace std;

#define mod 1000000007


int main()
{
	int n, k;
	cin >> n >> k;
	if(k == 0){
		cout << (long long int)n * n << endl;
		return 0;
	}
	long long int ans = 0;
	for(int i = k + 1; i <= n; i++){
		ans += (n / i) * (i - k) + max(0, n % i - k + 1);
		// cout << i << " " << ans << endl;
	}
	cout << ans << endl;
}