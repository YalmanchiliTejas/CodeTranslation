#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<functional>
#include<queue>
#define int long long
using namespace std;

signed main() {
	char a, b, c;
	cin >> a >> b >> c;
	string d;
	d += a;
	d += b;
	d += c;
	int e = stoi(d);
	if (e % 4) {
		puts("NO");
	}
	else {
		puts("YES");
	}
}