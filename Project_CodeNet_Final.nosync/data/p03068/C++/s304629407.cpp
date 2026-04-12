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
signed main() {
	ll n, k;
	string s;
	cin >> n >> s >> k;
	rep(i, n) {
		if (s[i] != s[k - 1])s[i] = '*';
	}
	cout << s << endl;
	ggr
}
