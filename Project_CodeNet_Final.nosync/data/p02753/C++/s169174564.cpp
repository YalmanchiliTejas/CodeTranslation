//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007LL
#define INF (1LL<<60LL)
//#define int long long
#define MAX_N (100001)
typedef long long ll;

using namespace std;



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool ans = false;
	string s; cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else cout << "Yes" << endl;

}