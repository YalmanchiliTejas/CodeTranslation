#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<random>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<unordered_map>
#include<time.h>
#define int long long
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef long double ld;
int n, a;
list<int>l;
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (n % 2 == 1) {
			if (i % 2 == 0)
				l.push_front(a);
			else
				l.push_back(a);
		}
		else {
			if (i % 2 == 0)
				l.push_back(a);
			else
				l.push_front(a);
		}
	}
	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		if (it == l.begin()) cout << (*it);
		else cout << " " << (*it);
		it++;
	}
	cout << endl;
}