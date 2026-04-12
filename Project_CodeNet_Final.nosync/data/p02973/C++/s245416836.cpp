#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
//#include<unordered_map>
//#include<unordered_set>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
#include <functional>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1Int<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 100005;
//////////////////////////////

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	Int n;
	cin >> n;

	vector<Int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	multiset<Int> s;
	for (int i = 0; i < n; i++) {
		Int now = a[i];
		auto itr = s.lower_bound(now);
		if (itr != s.begin()) {
			s.erase(--itr);
		}
		s.insert(now);
	}
	cout << s.size() << endl;

	return 0;
}
