#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
#define INF 114514
using namespace std;




int main(){
	while (1) {
		int i = 0, sum = 0, name = 0;
		for (i = 0; i < 5; i++) {
			int a, b;
			cin >> a >> b;
			if (a == 0 && b == 0) return 0;
			if (a + b > sum) {
				sum = a + b;
				name = i + 1;
			}
		}
		if (name == 1) cout << "A " << sum << endl;
		if (name == 2) cout << "B " << sum << endl;
		if (name == 3)cout << "C " << sum << endl;
		if (name == 4) cout << "D " << sum << endl;
		if (name == 5) cout << "E " << sum << endl;
	}
	return 0;
}