#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	multiset<int> st;
	int n;
	cin >> n;
	int a;
	cin >> a;
	st.insert(a);
	for (int i = 0; i < n-1; i++) {
		int a;
		cin >> a;
		auto o = st.multiset::lower_bound(a);
		if (o == st.begin()) {
			st.insert(a);
		}
		else {
			st.erase(--o);
			st.insert(a);
		}
	}
	cout << st.size() << endl;
	return 0;
}
