#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
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

ll N, X;
ll a[51];

ll f(ll n,ll x) {
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	else if (1 < x && x < a[n-1]+2) {
		return f(n-1,x-1);
	}
	else if (x == a[n-1]+2) {
		return f(n - 1, a[n - 1])+1;
	}
	else if (2+a[n-1]<x && x < 2*a[n-1]+3) {
		return f(n-1,x-a[n-1]-2)+1+f(n-1,a[n-1]);
	}
	else {
		return 2 * f(n - 1,a[n-1]) + 1;
	}
}



int main() {	
	cin >> N >> X;
	rep(i, 0, 51) {
		a[i] = 0;
	}
	a[0] = 1LL;
 	rep(i, 1, 51) {
		a[i] = 2 * a[i - 1] + 3;
	}
	
	cout << f(N, X) << endl;

	return 0;
}
