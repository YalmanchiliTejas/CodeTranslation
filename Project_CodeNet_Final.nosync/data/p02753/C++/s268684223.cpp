#pragma warning (disable:4996)
#include"bits/stdc++.h"
#include<cassert>
#define int long long
#define MRE assert(0);
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long mod = 998244353;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<int, P > PP;
signed main() {
	string s; cin >> s;
	if (s == "AAA" || s == "BBB")cout << "No" << endl;
	else puts("Yes");
}