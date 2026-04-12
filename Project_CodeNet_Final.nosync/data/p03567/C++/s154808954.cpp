#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<deque>
#include<string>
#include<random>
#include<stack>
#include<limits.h>
using namespace std;

signed main() {
	string a; cin >> a;
	for (int i = 0; i < a.length() - 1; i++) {
		if (a[i] == 'A'&&a[i + 1] == 'C') { puts("Yes"); return 0; }
	}
	puts("No");
}
