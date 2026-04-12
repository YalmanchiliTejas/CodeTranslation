#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
//もう二度とつかわん//
//    ↓ ↓　↓　　 //
#define ll long long
//    ↑　↑　↑    //
//フェルマー方程式の恨み//
#define rep(i,n) for(int i=0;i<n;i++)
#define ggr getchar(); getchar();return 0;
using namespace std;
ll a[22];
ll n;
signed main() {
	ll cnt = 0, ans = 0;
	cin >> n;
	rep(i, n)cin >> a[i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i])cnt++;
		}
		if (cnt == i)ans++;
		cnt = 0;
	}
	cout << ans + 1 << endl;
	ggr
}
