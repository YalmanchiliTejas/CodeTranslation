#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define N 100010
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define mod 1000000007
#define pii pair <int, int>
#define all(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = x; i <= y; i++)

using namespace std;

ll ans, n, k;

int main()
{
	cin >> n >> k;
	
	if (k==0) {
		cout << n*n;
		return 0;
	}
	
	ans += (n-k+1)*(n-k)/2;
//	cout << ans << "\n";
	for (ll i = k+1; i <= n; i++) {
		ll a = i+k;
		
		if (a > n)
			break;
		
		ll h = 0, t = n, m, res = 0;
		
		while (h <= t) {
			m = (h+t)/2;
			
			if (a+m*i > n)
				t = m-1;
			else
				h = m+1, res = max(res, m);
		}
//		cout<<i<<": " << res << "\n";
//		cout << i << ": " << n-(res*i+a)+1 << "\n";
//		if (res!=0)
//			ans+=(res-1)*(i-k);
		ans+=res*(i-k);
		if (res*i+a + (i-k-1) <= n)
			ans+=i-k;
		else
			ans+=n-(res*i+a)+1;
//		cout << i << ": " << res << "\n";
//		ans+=n-(res*i+a)+1;
//		ans+=res;
	}
	cout << ans;
}
