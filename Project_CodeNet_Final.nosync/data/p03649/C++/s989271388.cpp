//ITNOA
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


#define rep(i, s, e) for(int i = s; i < e; i ++)
#define X first
#define Y second

typedef long long ll;
typedef long double ld;

const int maxN = 50 + 5;
const int mod = 1000*1000*1000 + 7;
const int base = 701;
const int SQ = 500;
const int maxL = 20;

ll a[maxN];

int n;
ll get() {
	sort(a,a+n);
	int res = 0;
	while(a[n-1] >= n) {
	   	a[n-1] -= n;
   		for(int i = 0; i < n-1; i ++)
	 		a[i] ++;
		sort(a,a+n);
		res ++;		
	}	
	return res;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	ll ans = 0;
	while(true) {
		sort(a,a+n);
		if(a[n-1] < n) break;
		
		ll sum = 0;
		for(int i = 0; i < n; i ++)
			sum += a[i];
		if(sum <= 100*100) {
			ans += get();
			break;
		}

		ll dif = (a[n-1] - (n-1)) / n;
		//	cout << dif << endl;
	   	a[n-1] -= dif * n;
		for(int i = 0; i < n-1; i ++)
			a[i] += dif;
		
		ans += dif;	
	}

	cout << ans << endl;
	return 0;
}
