#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "math.h"
#include "assert.h"

using namespace std;

int inf = std::numeric_limits<int>().max();

#define BUFF ios::sync_with_stdio(false)
#define epsilon 1e-07
#define pi 2 * acos(0.0);
#define mod 1000000007   // 1e9+7
#define ll long long
#define cerr if(false)cerr
#define watch(x) cerr << #x << " = " << x << endl;

int main() {
	int n;
	cin >> n;
	vector<int> v(n); 
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	multiset<int> s;

	ll t = 1;
	s.insert(- v[0]);
	for(int i=1; i<n; i++) {
		auto it = s.upper_bound(-v[i]);	
		if (it != s.end()) {
			auto it1 = it;
			it1++;
			s.erase(it, it1);
		} else t++;
		s.insert( - v[i]);
	}
	cout << t << endl;
}
