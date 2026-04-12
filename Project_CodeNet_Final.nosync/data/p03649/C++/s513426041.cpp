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
	int n;
	cin >> n;
	long long int a[51];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	long long int ans = 0;
	while(a[0] >= n){
		long long int s = 0;
		for(int i = 0; i < n; i++){
			s += a[i] / n;
		}
		ans += s;
		for(int i = 0; i < n; i++){
			a[i] = (a[i] % n) + s - (a[i] / n);
		}
		sort(a, a + n);
		reverse(a, a + n);
	}
	cout << ans << endl;
}