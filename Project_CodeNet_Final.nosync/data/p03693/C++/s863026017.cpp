#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#define int long long
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
#define hash hush
typedef long long ll;
typedef long double ld;
int a[100000];
signed  main() {
	string a, b, c, d;
	cin >> a >> b >> c;
	d = a + b + c;
	if (stoll(d) % 4 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	getchar(); getchar();
}