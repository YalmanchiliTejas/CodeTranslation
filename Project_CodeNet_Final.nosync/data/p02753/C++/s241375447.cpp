#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>
#include <stack>
#include <limits>
#include <ctime>

using namespace std;

#define ll long long
#define sc(n) static_cast<ll>(n)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
	IO;
#ifdef _DEBUG
	ifstream cin("In.txt");
#endif	
	string st;
	cin >> st;
	sort(st.begin(), st.end());
	for (int i = 1; i < st.size(); i++) {
		if (st[i] != st[i - 1]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}