//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
typedef long long ll;

using namespace std;



signed main() {
	int n; cin >> n;
	int k = n / 15;
	int ans = n * 800 - k * 200;
	cout << ans << endl;
}